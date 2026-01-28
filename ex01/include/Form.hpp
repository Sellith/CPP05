/* *************************************************************************************************************** */
/*   Form.hpp                                                                                                      */
/*   By: lvan-bre                                                                   .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*                                                           ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*                                                      ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
/*                                                     oxodddddoooooolllllllolooooollloooollllolllllloooolccl;     */
/*                                                    'x:::cclccllllccccccccccclllclllllllllllllllll     .;;cl;    */
/*                                                    d;c::cc:cc:::;::c:c:cccccclccc:cccclllllll,         .:cl.    */
/*                                                      c;,;:;;::::;;::::c..,cccllcc:c;;:lloodk.                   */
/*                                                        'ooooooooodddxxkkkOOOkOOOOOOc:cclllloo'                  */
/*                                                           .XXXXXXXKKXXXXXXXXXXXXXXXkcccclcccllo                 */
/*                                                                 ,KKKKKXXXXXXXXXXXXK0.  .:ccllclll;.             */
/*                                                                                           .ccccccllc,.          */
/*                                                                                                 :::cl:          */
/*                                                                                                                 */
/* *************************************************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream> 

# define FORM_TOO_HIGH	std::string("form's inputed grade is invalid (too High)")
# define FORM_TOO_LOW	std::string("form's inputed grade is invalid (too Low)")
# define FORM_TOO_HIGH1	std::string("it's grade is too High for them to sign it")


class Bureaucrat;

class Form {

public:

	Form ( void );
	Form ( const std::string name, const int signGrade, const int execGrade );
	Form ( const Form & src );

	~Form ( void );

	Form & operator= ( const Form & src );

	void				beSigned ( Bureaucrat slave );
	const std::string	getName ( void );
	int					getSignGrade ( void ) const;
	int					getExecGrade ( void ) const;

	class gradeTooHighException : public std::exception {
		
		public:
			gradeTooHighException(std::string const msg);
			const char *	what() const throw();
			virtual ~gradeTooHighException() throw() ;

		private:
			gradeTooHighException();
			const std::string _msg;
	};

	class gradeTooLowException : public std::exception {
		
		public:
			gradeTooLowException(std::string const msg);
			const char *	what() const throw();
			virtual ~gradeTooLowException() throw();

		private:
			gradeTooLowException();
			const std::string _msg;
	};

	class formAlreadySigned : public std::exception {
		public:
			virtual const char *	what() const throw();
	};

private:

	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;

};

std::ostream &		operator<< (std::ostream & out, Form & src );

#endif
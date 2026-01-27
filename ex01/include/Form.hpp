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

	class gradeTooHighException : std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class gradeTooLowException : std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class formAlreadySigned : std::exception {
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
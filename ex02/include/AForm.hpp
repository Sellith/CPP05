/* *************************************************************************************************************** */
/*   AForm.hpp                                                                                                      */
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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream> 

#define EXEC_FORM_TOO_LOW	std::string("the form's execution's grade is not valid (too low)")
#define SIGN_FORM_TOO_LOW	std::string("the form's signature's grade is not valid (too low)")
#define EXEC_FORM_TOO_LOW1	std::string("it's execution's grade is too low")
#define SIGN_FORM_TOO_LOW1	std::string("it's signature's grade is too low")

class Bureaucrat;

class AForm {

public:

	AForm ( void );
	AForm ( const std::string name, const int signGrade, const int execGrade );
	AForm ( const AForm & src );

	virtual ~AForm ( void );

	AForm & operator= ( const AForm & src );

	void				beSigned ( Bureaucrat slave );
	const std::string	getName ( void ) const;
	int					getSignGrade ( void ) const;
	int					getExecGrade ( void ) const;
	bool				checkRequierements ( Bureaucrat const & executor ) const;
	virtual void		execute ( Bureaucrat const & executor ) const = 0;

	/* ****************** */
	/* Exceptions classes */
	/* ****************** */

	class signGradeTooHighException : public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class execGradeTooHighException : public std::exception {
		public:
			virtual const char *	what() const throw();
	};
	
	class formAlreadySigned : public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class formNotSigned : public std::exception {
		public:
			virtual const char *	what() const throw();
	};

	class signGradeTooLowException : public std::exception {
		
		public:
			signGradeTooLowException(std::string const msg);
			const char *	what() const throw();
			virtual ~signGradeTooLowException() throw() ;

		private:
			signGradeTooLowException();
			const std::string _msg;
	};

	class execGradeTooLowException : public std::exception {
		
		public:
			execGradeTooLowException(std::string const msg);
			const char *	what() const throw();
			virtual ~execGradeTooLowException() throw();

		private:
			execGradeTooLowException();
			const std::string _msg;
	};

private:

	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;

};

std::ostream &		operator<< (std::ostream & out, AForm & src );

#endif
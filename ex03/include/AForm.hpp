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

class Bureaucrat;

class AForm {

public:

	AForm ( void );
	AForm ( const std::string name, const int signGrade, const int execGrade );
	AForm ( const AForm & src );

	virtual ~AForm ( void );

	AForm & operator= ( const AForm & src );

	const std::string	getName ( void ) const;
	int					getSignGrade ( void ) const;
	int					getExecGrade ( void ) const;
	void				beSigned ( Bureaucrat slave );
	bool				checkRequierements ( Bureaucrat const & executor ) const;
	virtual void		execute ( Bureaucrat const & executor ) const = 0;

	class gradeTooHighException : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return "the form's grade is not valid";
			}
	};

	class signGradeTooLowException : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return "his grade is too low to sign it";
			}
	};

	class formAlreadySigned : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return "this form is already signed";
			}
	};

	class formNotSigned : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return "this form is not signed";
			}
	};

	class execGradeTooLowSigned : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return "his Grade is too low to execute it";
			}
	};

private:

	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;

};

std::ostream &		operator<< (std::ostream & out, AForm & src );

#endif
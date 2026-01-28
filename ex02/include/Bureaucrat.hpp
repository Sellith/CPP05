/* *************************************************************************************************************** */
/*   Bureaucrat.hpp                                                                                                  */
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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define BUREAUCRAT_TOO_HIGH	std::string("'s grade is too High")
# define BUREAUCRAT_TOO_LOW		std::string("'s grade is too Low")
# define ERROR					std::string("Error : ")
# define PROMOTION_FAIL			std::string("can't promote because ")
# define DEMOTE_FAIL			std::string("can't demote because ")
# define CHANGE_GRADE_FAIL		std::string("can't change grade because the newGrade")

class AForm ;

class Bureaucrat {

public:

	Bureaucrat ( void );
	Bureaucrat ( std::string const name, int const grade );
	Bureaucrat ( const Bureaucrat & src );
	
	~Bureaucrat ( void );

	Bureaucrat &		operator= ( const Bureaucrat & src );

	const std::string	getName ( void ) const;
	int					getGrade ( void ) const;

	void				promotion ( void );
	void				demotion ( void );
	void				put_grade ( int newGrade );
	void				signForm ( AForm & form );
	void				executeForm ( AForm const & form );

	class GradeTooHighException : public std::exception {
		
		public:
			GradeTooHighException(std::string const msg);
			const char *	what() const throw();
			virtual ~GradeTooHighException() throw() ;

		private:
			GradeTooHighException();
			const std::string _msg;
	};

	class GradeTooLowException : public std::exception {
		
		public:
			GradeTooLowException(std::string const msg);
			const char *	what() const throw();
			virtual ~GradeTooLowException() throw();

		private:
			GradeTooLowException();
			const std::string _msg;
	};

private:

	const std::string	_name;
	int					_grade;

};

std::ostream &		operator<< (std::ostream & out, Bureaucrat & src );

#endif
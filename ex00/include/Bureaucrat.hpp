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

class Bureaucrat {

public:

	Bureaucrat ( void );
	Bureaucrat ( const Bureaucrat & src );
	
	~Bureaucrat ( void );

	Bureaucrat &		operator= ( const Bureaucrat & src );

	const std::string	getName ( void );
	int					getGrade ( void );

	void				promotion ( void );
	void				demotion ( void );
	void				put_grade ( int newGrade );

	class gradeTooHighException : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return ("'s grade is too high");
			}
	};

	class gradeTooLowException : std::exception {
		
		public:
			virtual const char *	what() const throw() {
				return ("'s grade is too Low");
			}
	};

private:

	const std::string	_name;
	int					_grade;

};

std::ostream &		operator<< (std::ostream & out, Bureaucrat & src );

#endif
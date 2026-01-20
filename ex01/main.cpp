/* *************************************************************************************************************** */
/*   main.cpp                                                                                                      */
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

#include "Bureaucrat.hpp"

int	main ( void )
{
	Bureaucrat a("Alex");

	a.put_grade(150);
	std::cout << a << std::endl;

	a.demotion();

	try {
		if (a.getGrade() > 150)
			throw Bureaucrat::gradeTooLowException();
		else if (a.getGrade() < 1)
			throw Bureaucrat::gradeTooHighException();
	}
	
	catch (Bureaucrat::gradeTooLowException& e) {
		std::cout << a << e.what() << std::endl;
	}

	catch (Bureaucrat::gradeTooHighException& e) {
		std::cout << a << e.what() << std::endl;
	}

	std::cout << "\n";
	a.put_grade(1);
	std::cout << a << std::endl;
	a.promotion();
	
	try {
		if (a.getGrade() > 150)
			throw Bureaucrat::gradeTooLowException();
		else if (a.getGrade() < 1)
			throw Bureaucrat::gradeTooHighException();
	}
	
	catch (Bureaucrat::gradeTooLowException& e) {
		std::cout << a << e.what() << std::endl;
	}

	catch (Bureaucrat::gradeTooHighException& e) {
		std::cout << a << e.what() << std::endl;
	}

	return (0);
}
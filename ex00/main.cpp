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
	Bureaucrat a;
	
	try {	
		a.put_grade(150);
		std::cout << a << std::endl;
		a.demotion();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try{
		std::cout << "\n";
		a.put_grade(1);
		std::cout << a << std::endl;
		a.promotion();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Bureaucrat b("Peasent", 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n";

	try {
		Bureaucrat c("God", 0);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
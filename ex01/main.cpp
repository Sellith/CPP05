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

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main ( void )
{
	Bureaucrat	a("Random", 150);
	Bureaucrat	Pdg("Chief", 1);

	Form		randomForm("random1", 150, 150);
	Form		form("random2", 150, 150);
	Form		actions("the actions papers", 10, 5);

	std::cout << randomForm << std::endl;
	a.signForm(randomForm);
	std::cout << "\n";

	std::cout << form << std::endl;
	Pdg.signForm(form);
	std::cout << "\n";

	std::cout << actions << std::endl;
	a.signForm(actions);
	Pdg.signForm(actions);
	std::cout << "\n";

	try {
		Form		wrongForm("WrongForm", 0, 0);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form		wrongForm("WrongForm", 50, 151);
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
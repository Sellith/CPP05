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

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main ( void )
{
	Intern		Random;
	AForm *		newForm;
	Bureaucrat	Pdg("Pdg", 1);

	newForm = Random.makeForm("shrubbery creation", "home");
	if (newForm) {
		Pdg.signForm(*newForm);
		Pdg.executeForm(*newForm);
	}
	
	std::cout << "\n";

	delete newForm;

	newForm = Random.makeForm("robotomy request", "bip boop");
	if (newForm) {
		Pdg.signForm(*newForm);
		Pdg.executeForm(*newForm);
	}

	std::cout << "\n";

	delete newForm;

	newForm = Random.makeForm("presidential pardon", "Steve the fish");
	if (newForm) {
		Pdg.signForm(*newForm);
		Pdg.executeForm(*newForm);
	}

	std::cout << "\n";

	delete newForm;

	newForm = Random.makeForm("eifeigw", "failure management");
	if (newForm) {
		Pdg.signForm(*newForm);
		Pdg.executeForm(*newForm);
	}
}
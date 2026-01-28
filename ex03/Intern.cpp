/* *************************************************************************************************************** */
/*   Intern.cpp                                                                                                    */
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

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern ( void ) {}
Intern::Intern ( Intern const & src ) {(void)src;}
Intern::~Intern ( void ) {}

Intern &	Intern::operator= ( Intern const & src ) {(void)src; return (*this);}


AForm *	Intern::makeForm ( std::string const name, std::string const target ) 
{
	AForm *	form;

	std::string existing[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	int i = 0;
	while (i < 3 && name != existing[i])
		i++;
	
	switch (i) {
		case 0: form = new ShrubberyCreationForm(name, target);
		std::cout << "Intern creates a Shrubbery Creation Form" << std::endl;
		return (form);

		case 1: form = new RobotomyRequestForm(name, target);
		std::cout << "Intern creates a Robotomy Request Form" << std::endl;
		return (form);

		case 2: form = new PresidentialPardonForm(name, target);
		std::cout << "Intern creates a Presidential Pardon Form" << std::endl;
		return (form);

		default: std::cout << "Yikes ! The intern put in the wrong name again ..." << std::endl;
		return (NULL);
	}
}
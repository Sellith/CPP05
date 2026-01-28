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

int	main ( void )
{
	Bureaucrat	a;
	Bureaucrat	captn("captn", 90);
	Bureaucrat	chief("chief", 30);
	Bureaucrat	Pres("Pdg", 1);

	ShrubberyCreationForm	Shrub;
	RobotomyRequestForm		Robot;
	PresidentialPardonForm	Anar;
	ShrubberyCreationForm	Shrub2(Shrub);
	RobotomyRequestForm		Robot2(Robot);
	PresidentialPardonForm	Anar2(Anar);
	ShrubberyCreationForm	Shrub3(Shrub);
	RobotomyRequestForm		Robot3(Robot);
	PresidentialPardonForm	Anar3(Anar);

	a.signForm(Shrub);
	a.signForm(Robot);
	a.signForm(Anar);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	captn.signForm(Shrub);
	captn.signForm(Robot);
	captn.signForm(Anar);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";


	chief.signForm(Shrub2);
	chief.signForm(Robot2);
	chief.signForm(Anar2);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	Pres.signForm(Shrub3);
	Pres.signForm(Robot3);
	Pres.signForm(Anar3);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";


	a.executeForm(Shrub3);
	captn.executeForm(Shrub3);
	chief.executeForm(Shrub3);
	Pres.executeForm(Shrub3);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	a.executeForm(Robot);
	captn.executeForm(Robot3);
	chief.executeForm(Robot3);
	Pres.executeForm(Robot3);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	a.executeForm(Anar3);
	captn.executeForm(Shrub3);
	chief.executeForm(Shrub3);
	Pres.executeForm(Shrub3);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	captn.executeForm(Anar3);
	chief.executeForm(Anar3);
	Pres.executeForm(Anar3);
	std::cout << "\n";
	std::cout << "-------------------------------------------------------------------\n\n";

	return (0);
}
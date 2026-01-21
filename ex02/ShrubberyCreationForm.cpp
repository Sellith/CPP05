/* *************************************************************************************************************** */
/*   ShrubberyCreationForm.cpp                                                                                     */
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
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) :
	AForm("yip fox", 145, 137),
	_target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm ( std::string const name, std::string const target) :
	AForm(name, 145, 137),
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) :
	AForm(src),
	_target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm ( void ) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator= ( ShrubberyCreationForm const & src )
{
	if ( this != &src ) {
		AForm::operator=(src);
		(std::string)_target = src._target;
	}

	return ( *this );
}

void	ShrubberyCreationForm::execute ( Bureaucrat const & executor ) const
{
	try {
		AForm::checkRequierements(executor);
	}

	catch (AForm::formNotSigned& e) {
		std::cout << executor.getName() << " couldn't execute " << getName() << " because " << e.what() << std::endl;;
		return ;
	}
	
	catch (AForm::execGradeTooLowSigned& e) {
		std::cout << executor.getName() << " couldn't execute " << getName() << " because " << e.what() << std::endl;;
		return ;
	}

	std::cout << "Creating " << _target << "_shrubbery in the " << std::endl;
}
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
	AForm("home tree", 145, 137),
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

	if (!AForm::checkRequierements(executor))
		return ;

	std::string 	filename = _target + "_shrubbery";
	std::ofstream	outf(filename.c_str());

	if (!outf.is_open()) {
		throw failedToOpenFileException();
		return ;
	}

	std::cout << "Creating " << filename << " in current directory" << std::endl;

	outf << 
	"               ,@@@@@@@," << "\n"
	"       ,,,.   ,@@@@@@/@@,  .oo8888o." << "\n"
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << "\n"
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n"
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << "\n"
	" 	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << "\n"
	"   `&%\\ ` /%&'    |.|        \\ '|8'" << "\n"
	"       |o|        | |         | |" << "\n"
	"       |.|        | |         | |" << "\n"
	"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	outf.close();
	return ;
}
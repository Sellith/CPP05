/* *************************************************************************************************************** */
/*   RobotomyRequestForm.cpp                                                                                       */
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

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) : 
	AForm("bip bip boop", 72, 45),
	_target("Alita") {}

RobotomyRequestForm::RobotomyRequestForm ( std::string const name, std::string const target ) :
	AForm(name, 72, 45), 
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const & src ) :
	AForm(src),
	_target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm ( void ) {}

RobotomyRequestForm &	RobotomyRequestForm::operator= ( RobotomyRequestForm const & src )
{
	if ( this != &src ) {
		AForm::operator=(src);
		(std::string)_target = src._target;
	}
	
	return ( *this );
}

void	RobotomyRequestForm::execute ( Bureaucrat const & executor ) const
{
	if (!AForm::checkRequierements(executor))
		return ;

	std::cout << "Drilling noises... Pending... " << std::endl;

	if (std::rand() % 2)
		std::cout << "informing : " << _target << "'s robotomy has been successfull !" << std::endl;
	else
		std::cout << "informing : " << _target << "'s robotomy has failed !" << std::endl;
	return ;
}
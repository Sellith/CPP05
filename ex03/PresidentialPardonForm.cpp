/* *************************************************************************************************************** */
/*   PresidentialPardonForm.cpp                                                                                    */
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

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) : 
	AForm("We shall Rise", 25, 5),
	_target("Anars") {}

PresidentialPardonForm::PresidentialPardonForm ( const std::string name, const std::string target ) : 
	AForm(name, 25, 5),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm ( const PresidentialPardonForm & src ) : 
	AForm(src),
	_target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm ( void ) {}

PresidentialPardonForm & PresidentialPardonForm::operator= ( const PresidentialPardonForm & src )
{
	if ( this != &src ) {
		AForm::operator=(src);
		(std::string)_target = src._target;
	}

	return ( *this );
}


void	PresidentialPardonForm::execute ( Bureaucrat const & executor ) const
{
	if (!AForm::checkRequierements(executor))
		return ;

	std::cout << "I hereby inform you that " << _target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return ;
}
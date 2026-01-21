/* *************************************************************************************************************** */
/*   AForm.cpp                                                                                                      */
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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm ( void ) : 
	_name("a random paperWork"),
	_signed(false),
	_signGrade(150),
	_execGrade(150) {}

AForm::AForm ( const std::string name, const int signGrade, const int execGrade ) : 
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {}

AForm::AForm ( const AForm & src ) :
	_name(src._name),
	_signed(src._signed),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade) {}

AForm::~AForm ( void ) {}

AForm & AForm::operator= ( const AForm & src) 
{
	if ( this != &src ) {
		_signed = src._signed;
		(std::string)_name = src._name;
	}

	return ( *this ); 
}

std::ostream &	operator<< ( std::ostream & out, AForm & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getSignGrade();
	return (out);
}

void	AForm::beSigned ( Bureaucrat slave )
{
	if (_signed) {
		throw AForm::formAlreadySigned();
		return ;
	}

	if (slave.getGrade() < 1) {
		throw Bureaucrat::gradeTooHighException();
		return ;
	}

	if (slave.getGrade() > 150) {
		throw Bureaucrat::gradeTooLowException();
		return ;
	}
	
	if (_signGrade < 1 || _execGrade < 1) {
		throw AForm::gradeTooHighException();
		return ;
	}

	if (slave.getGrade() > _signGrade ) {
		throw AForm::signGradeTooLowException();
		return ;
	}

	_signed = true;
	std::cout << slave.getName() << " signed " << _name << std::endl;
}

int	AForm::getSignGrade ( void ) const
{
	return (_signGrade);
}

int	AForm::getExecGrade ( void ) const
{
	return (_execGrade);
}

const std::string AForm::getName ( void ) const
{
	return (_name);
}

void	AForm::checkRequierements ( Bureaucrat const & executor ) const
{
	if (!_signed) {
		throw formNotSigned();
		return ;
	}
	if (executor.getGrade() > _execGrade) {
		throw execGradeTooLowSigned();
		return ;
	}
	
}
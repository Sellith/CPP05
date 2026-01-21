/* *************************************************************************************************************** */
/*   Form.cpp                                                                                                      */
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

Form::Form ( void ) : 
	_name("a random paperWork"),
	_signed(false),
	_signGrade(150),
	_execGrade(150) {}

Form::Form ( const std::string name, const int signGrade, const int execGrade ) : 
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {}

Form::Form ( const Form & src ) :
	_name(src._name),
	_signed(src._signed),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade) {}

Form::~Form ( void ) {}

Form & Form::operator= ( const Form & src) 
{
	if ( this != &src ) {
		_signed = src._signed;
		(std::string)_name = src._name;
	}

	return ( *this ); 
}

std::ostream &	operator<< ( std::ostream & out, Form & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getSignGrade();
	return (out);
}

void	Form::beSigned ( Bureaucrat slave )
{
	if (_signed) {
		throw Form::formAlreadySigned();
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
	
	if (_signGrade < 1) {
		throw Form::gradeTooHighException();
		return ;
	}

	if (slave.getGrade() > _signGrade ) {
		throw Form::gradeTooLowException();
		return ;
	}

	_signed = true;
	std::cout << slave.getName() << " signed " << _name << std::endl;
}

int	Form::getSignGrade ( void )
{
	return (_signGrade);
}

int	Form::getExecGrade ( void )
{
	return (_execGrade);
}

const std::string Form::getName ( void )
{
	return (_name);
}

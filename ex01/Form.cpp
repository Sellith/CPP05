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

Form::Form ( const std::string name, const int signGrade, const int execGrade ) : 
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {}

Form::Form ( const Form & src ) :
	_name(src._name),
	_signed(src._signed),
	_signGrade(_signGrade),
	_execGrade(src._execGrade) {}

Form::~Form ( void ) {}

Form & Form::operator= ( const Form & src) 
{
	if ( this != &src )
		_signed = src._signed;
		(std::string)_name = src._name;

	return ( *this ); 
}

std::ostream &	operator<< ( std::ostream & out, Form & src )
{
	out << src.getName() << ", bureaucrat grade " << src.getSignGrade();
	return (out);
}

void	Form::beSigned ( Bureaucrat slave )
{
	if (slave.getGrade() > _signGrade )
		throw Form::gradeTooLowException();
		return ;

	if (_signed)
		throw Form::formAlreadySigned();
		return ;

	_signed = true;
}

const int	Form::getSignGrade ( void )
{
	return (_signGrade);
}

const int	Form::getExecGrade ( void )
{
	return (_execGrade);
}

const std::string Form::getName ( void )
{
	return (_name);
}

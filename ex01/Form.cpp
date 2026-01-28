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

/* Exception implementation */

const char *	Form::formAlreadySigned::what() const throw() {return "this form is already signed";}

Form::gradeTooHighException::gradeTooHighException(std::string const msg) : _msg(msg) {}
Form::gradeTooHighException::~gradeTooHighException() throw() {}
const char *	Form::gradeTooHighException::what() const throw()
{return (_msg.c_str());}

Form::gradeTooLowException::gradeTooLowException(std::string const msg) : _msg(msg) {}
Form::gradeTooLowException::~gradeTooLowException() throw() {}
const char *	Form::gradeTooLowException::what() const throw()
{return (_msg.c_str());}

Form::Form ( void ) : 
	_name("a random paperWork"),
	_signed(false),
	_signGrade(150),
	_execGrade(150) {}

Form::Form ( const std::string name, const int signGrade, const int execGrade ) : 
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw gradeTooLowException(ERROR + _name + FORM_TOO_LOW);
	if (signGrade < 1 || execGrade < 1)
		throw gradeTooHighException(ERROR + _name + FORM_TOO_HIGH);
}

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
	out << src.getName() << ", signature grade is " << src.getSignGrade() << ", and execution grade is " << src.getExecGrade();
	return (out);
}

void	Form::beSigned ( Bureaucrat slave )
{
	if (_signed) {
		throw Form::formAlreadySigned();
		return ;
	}

	if (slave.getGrade() > _signGrade ) {
		throw Form::gradeTooHighException(FORM_TOO_HIGH1);
		return ;
	}

	_signed = true;
	std::cout << slave.getName() << " signed " << _name << std::endl;
}

int	Form::getSignGrade ( void ) const
{return (_signGrade);}

int	Form::getExecGrade ( void ) const
{return (_execGrade);}

const std::string Form::getName ( void )
{return (_name);}

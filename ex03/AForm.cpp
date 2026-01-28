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

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::signGradeTooLowException::signGradeTooLowException(std::string const msg) : _msg(msg) {}
AForm::signGradeTooLowException::~signGradeTooLowException() throw() {}
const char *	AForm::signGradeTooLowException::what() const throw()
{return (_msg.c_str());}

AForm::execGradeTooLowException::execGradeTooLowException(std::string const msg) : _msg(msg) {}
AForm::execGradeTooLowException::~execGradeTooLowException() throw() {}
const char *	AForm::execGradeTooLowException::what() const throw()
{return (_msg.c_str());}

const char *	AForm::signGradeTooHighException::what() const throw() {return "the form's signature's grade is not valid (too high)";}
const char *	AForm::execGradeTooHighException::what() const throw() {return "the form's execution's grade is not valid (too high)";}
const char *	AForm::formAlreadySigned::what() const throw() {return "this form is already signed";}
const char *	AForm::formNotSigned::what() const throw() {return "this form is not signed";}

AForm::AForm ( void ) : 
	_name("a random paperWork"),
	_signed(false),
	_signGrade(150),
	_execGrade(150) {}

AForm::AForm ( const std::string name, const int signGrade, const int execGrade ) : 
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade > 150)
		throw signGradeTooLowException(ERROR + _name + SIGN_FORM_TOO_LOW);
	else if (signGrade < 1 )
		throw signGradeTooHighException();
	if (execGrade > 150)
		throw execGradeTooLowException(ERROR + _name + EXEC_FORM_TOO_LOW);
	else if (execGrade < 1)
		throw execGradeTooHighException();
}

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
	out << src.getName() << ", signature grade is " << src.getSignGrade() << ", and execution grade is " << src.getExecGrade();
	return (out);
}

void	AForm::beSigned ( Bureaucrat slave )
{
	if (_signed) {
		throw formAlreadySigned();
		return ;
	}

	if (slave.getGrade() > _signGrade ) {
		throw signGradeTooLowException(SIGN_FORM_TOO_LOW1);
		return ;
	}

	_signed = true;
	std::cout << slave.getName() << " signed " << _name << std::endl;
}

int	AForm::getSignGrade ( void ) const
{return (_signGrade);}

int	AForm::getExecGrade ( void ) const
{return (_execGrade);}

const std::string AForm::getName ( void ) const
{return (_name);}

bool	AForm::checkRequierements ( Bureaucrat const & executor ) const
{
	if (!_signed) {
		throw formNotSigned();
		return (false);
	}
	if (executor.getGrade() > _execGrade) {
		throw execGradeTooLowException(EXEC_FORM_TOO_LOW1);
		return (false);
	}
	return (true);
}


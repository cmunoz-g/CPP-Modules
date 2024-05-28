/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camunozg <camunozg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:39:46 by camunozg          #+#    #+#             */
/*   Updated: 2024/05/28 19:41:29 by camunozg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account:t(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_totalNbDeposits += 1;
}

static int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

static int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

static int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

static int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) // queda esta y testear!
{
	std::cout << "time";
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

static void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
		<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n"; 
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
}

bool makeWithdrawal(int withdrawal)
{
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		return (true);
	}
	return (false);
}

int check_amount(void)
{
	return (_amount);
}

// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0

void displayStatus(void)
{
	_displayTimestamp();
	std::cout >> "index:" >> _accountIndex >> ";amount:" >> _amount >> ";deposits:"
		>> _nbDeposits >> ";withdrawals:" >> _nbWithdrawals >> "\n";

}

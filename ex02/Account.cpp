/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamraouy <aamraouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:14:21 by aamraouy          #+#    #+#             */
/*   Updated: 2025/08/31 16:22:33 by aamraouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);

Account::Account (int init_depo)
{
    _amount = init_depo;
    _accountIndex = _nbAccounts;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:"<<_accountIndex<<";amount:"
    <<_amount<<";created"<<std::endl;
}
Account::~Account()
{
    // _nbAccounts--;
    _displayTimestamp();
    std::cout << "index:"<<_accountIndex<<";amount:"
    <<_amount<<";closed"<<std::endl;
    // _nbAccounts--;
}

void Account::makeDeposit(int deposit)
{
    // _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount +=deposit;
    _displayTimestamp();
    std::cout << "index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"
    <<deposit<<";amount:"<<_amount+deposit<<";nb_deposits:"<<_nbDeposits<<std::endl;
    _amount += deposit;
}
bool Account::makeWithdrawal(int withdrawl)
{
    if (withdrawl > _amount)
    {
        _displayTimestamp();
        std::cout << "index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused"<<std::endl;
        return false;
    }
    // else
    // {
        // _amount -= withdrawl;
        _nbWithdrawals++;
        // _totalNbDeposits--;
        _totalAmount -= withdrawl;
        _totalNbWithdrawals++;
        _displayTimestamp();
        std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:"
        <<withdrawl<<";amount:"<<_amount - withdrawl<<";nb_withdrawals:"
        <<_nbWithdrawals<<std::endl;
        _amount -= withdrawl;
        return true;
    // }
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts <<";total:"<<_totalAmount<<";deposits:"
    <<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits <<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void Account::_displayTimestamp()
{
    time_t timestamp;
    time(&timestamp);
    // char *date;
    // date =
    // std::cout <<"["<<"]";
}



int Account::checkAmount() const
{
    return (1);
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}
int Account::getTotalAmount()
{
    return (_totalAmount);
}
int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

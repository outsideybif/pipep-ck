#pragma once
#define _WIN32_WINNT 0x0501
#define BOOST_BIND_NO_PLACEHOLDERS

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <conio.h>
using boost::asio::ip::udp;

#include "HumanCapitalStrategy.h"
#include "HumanCapitalAction.h"
#include "HumanCapitalState.h"
#include "HumanCapitalLooper.h"
﻿//
// Day10.xaml.h
// Declaration of the Day10 class
//

#pragma once

#include "Day10.g.h"

namespace AdventOfCode2018_UI
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Day10 sealed
	{
	public:
		Day10();
	private:
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DispatcherTimer_Tick(Platform::Object^ sender, Platform::Object^ e);
		int ticks;
		int seconds;
		std::string input;
		Windows::UI::Xaml::DispatcherTimer^ timer;
		std::map<std::pair<int, int>, std::pair<int, int>> positionsAndVelocities;
		std::vector<std::tuple<int, int, int, int>> posAndVel;
		std::string ReadInput();
		void PlayPause_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void StepBack_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void StepForward_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}


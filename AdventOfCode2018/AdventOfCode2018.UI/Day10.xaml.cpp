//
// Day10.xaml.cpp
// Implementation of the Day10 class
//

#include "pch.h"
#include "Day10.xaml.h"

using namespace AdventOfCode2018_UI;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Shapes;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

Day10::Day10()
{
	InitializeComponent();
}


void AdventOfCode2018_UI::Day10::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	ticks = 0;
	timer = ref new DispatcherTimer;
	timer->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &AdventOfCode2018_UI::Day10::DispatcherTimer_Tick);
	TimeSpan t;
	t.Duration = 1000000;
	timer->Interval = t;
	timer->Start();

	//auto x = ref new System::Random();
	for (size_t i = 0; i < 384; i++)
	{
		auto x = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandomNumber() % 10000;
		auto y = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandomNumber() % 10000;
		auto rect = ref new Rectangle();
		rect->Width = 6;
		rect->Height = 6;
		rect->Fill = ref new SolidColorBrush(Windows::UI::Colors::Black);
		Canvas::SetTop(rect, y);
		Canvas::SetLeft(rect, x);

		this->canvas->Children->Append(rect);
	}
}

void AdventOfCode2018_UI::Day10::DispatcherTimer_Tick(Platform::Object^ sender, Platform::Object^ e)
{
	for (auto const & c : this->canvas->Children)
	{
		auto xDir = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandomNumber() % 2;
		auto yDir = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandomNumber() % 2;
		double y = Canvas::GetTop(c);
		double x = Canvas::GetLeft(c);
		Canvas::SetTop(c, y + (yDir == 0 ? 6 : -6));
		Canvas::SetLeft(c, x + (xDir == 0 ? 6 : -6));
	}

	ticks++;
	if (ticks == 1000)
	{
		timer->Stop();
	}
}

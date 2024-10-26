#include "CppUnitTest.h"
#include "..\SWE_App\ButtonFactory.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ButtonFactoryTests
{
	TEST_CLASS(ButtonFactoryTests)
	{
	public:
       
		TEST_METHOD(CreateNumOpButton_NotNull) 
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;
			wxString label = "1";

			wxButton* button = factory.CreateNumOpButton(parent, id, label);

			Assert::IsNotNull(button);
		}

		TEST_METHOD(CreateNumOpButton_ID)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = 100;
			wxString label = "1";

			wxButton* button = factory.CreateNumOpButton(parent, id, label);

			Assert::AreEqual(100, button->GetId());
		}

		TEST_METHOD(CreateNumOpButton_Label) 
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;
			wxString label = "1";

			wxButton* button = factory.CreateNumOpButton(parent, id, label);

			Assert::AreEqual("1", button->GetLabel());
		}

		TEST_METHOD(CreateEqualsButton_NotNull)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;

			wxButton* button = factory.CreateEqualsButton(parent, id);

			Assert::IsNotNull(button);
		}

		TEST_METHOD(CreateEqualsButton_ID)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = 200;

			wxButton* button = factory.CreateEqualsButton(parent, id);

			Assert::AreEqual(200, button->GetId());
		}

		TEST_METHOD(CreateEqualsButton_Label)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;

			wxButton* button = factory.CreateEqualsButton(parent, id);

			Assert::AreEqual("=", button->GetLabel());
		}

		TEST_METHOD(CreateDeleteButton_NotNull)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;

			wxButton* button = factory.CreateDeleteButton(parent, id);

			Assert::IsNotNull(button);
		}

		TEST_METHOD(CreateDeleteButton_ID)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = 300;

			wxButton* button = factory.CreateDeleteButton(parent, id);

			Assert::AreEqual(300, button->GetId());
		}

		TEST_METHOD(CreateClearButton_NotNull)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = wxID_ANY;
			
			wxButton* button = factory.CreateClearButton(parent, id);

			Assert::IsNotNull(button);
		}

		TEST_METHOD(CreateClearButton_ID)
		{
			ButtonFactory factory;
			wxFrame* tempFrame = new wxFrame(nullptr, wxID_ANY, "Temp Frame");
			wxWindow* parent = new wxWindow(tempFrame, wxID_ANY);
			wxWindowID id = 400;

			wxButton* button = factory.CreateClearButton(parent, id);

			Assert::AreEqual(400, button->GetId());
		}

	};
}

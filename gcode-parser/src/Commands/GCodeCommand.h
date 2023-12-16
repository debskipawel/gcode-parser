#pragma once

namespace GCP
{
	class GCodeCommandVisitor;

	class GCodeCommand
	{
	public:
		unsigned int m_LineNumber;

	protected:
		virtual void Accept(GCodeCommandVisitor& visitor) = 0;

		friend class GCodeCommandVisitor;
	};
}

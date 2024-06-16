#pragma once

#include <chrono>

namespace Pecan {

	namespace TimeUtils
	{

		typedef std::chrono::high_resolution_clock::time_point StdTimePoint;

		/// Enum for different time units
		enum TimeUnit {
			NanoSeconds = 0,
			MicroSeconds = 1,
			MilliSeconds = 2,
			Seconds = 3,
			Minutes = 4,
			Hours = 5,
			Days = 6
		};

		/// Timer class used to keep track of elapsed time since a given moment.
		class Timer
		{
		public:
			/// Creates a timer. Starts timing immediately
			Timer();

			/// Resets timer. Begins from 0 immediately.
			void reset();

			/// Returns the currently elapsed time since the timer was started.
			/// @param timeUnit - Time unit in which the elapsed time will be returned
			/// @return Elapsed time in the given time unit
			float getTime(TimeUnit timeUnit = TimeUnit::Seconds) const;
		private:
			/// Point in time when the timer was started.
			StdTimePoint startTime;
		};

	} // namespace TimeUtils

} // namespace Pecan
/* -*- c++ -*- */
/*
 * Copyright 2018 Lime Microsystems info@limemicro.com
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_LIMESDR_SINK_H
#define INCLUDED_LIMESDR_SINK_H

#include <limesdr/api.h>
#include <gnuradio/block.h>

namespace gr
{
  namespace limesdr
  {
    class LIMESDR_API sink : virtual public gr::block
    {
    public:
	typedef boost::shared_ptr<sink> sptr;
	/*!
	* @brief Return a shared_ptr to a new instance of sink.
	*
	* To avoid accidental use of raw pointers, sink's
	* constructor is private.  limesdr::sink::make is the public
	* interface for creating new instances.
	* 
	* @param serial Device serial number. Cannot be left blank.
	*
	* @param device_type LimeSDR-Mini(1), LimeSDR-USB(2).
	*
	* @param chip_mode SISO(1), MIMO(2).
	*
	* @param channel Select channel when in SISO mode: A(0),B(1).
	*
	* @param file_switch Load settings from file: NO(0),YES(1).
	*
	* @param filename Path to file if file switch is turned on.
	*
	* @param rf_freq TX center frequency in Hz.
	*
	* @param samp_rate sample rate in S/s.
	*
	* @param oversample oversample value. Valid values are: 0(default),1,2,4,8,16,32.    
	*
	* @param calibration_ch0 Turn calibration channel 0: OFF(0),ON(1).
	*
	* @param calibr_bandw_ch0 Calibration bandwidth channel 0 [2.5e6,120e6] Hz.
	*
	* @param calibration_ch1 Turn calibration channel 1: OFF(0),ON(1).
	*
	* @param calibr_bandw_ch1 Calibration bandwidth channel 1 [2.5e6,120e6] Hz.
	*
	* @param pa_path_mini PA path LimeSDR-Mini: BAND1(1),BAND2(2).
	*
	* @param pa_path_ch0 PA path LimeSDR-USB channel 0: BAND1(1),BAND2(2).
	*
	* @param pa_path_ch1 PA path LimeSDR-USB channel 1: BAND1(1),BAND2(2).
	*
	* @param analog_filter_ch0 Turn analog filter channel 0: OFF(0),ON(1).
	*
	* @param analog_bandw_ch0 LPF bandwidth channel 0 [1.5e6,130e6] Hz.
	*
	* @param analog_filter_ch1 Turn analog filter channel 1: OFF(0),ON(1).
	*
	* @param analog_bandw_ch1 LPF bandwidth channel 1 [1.5e6,130e6] Hz.
	*
	* @param digital_filter_ch0 Turn digital filter channel 0: OFF(0),ON(1).
	*
	* @param digital_bandw_ch0 Digital filter bandwidth channel 0.
	*
	* @param digital_filter_ch1 Turn digital filter channel 1: OFF(0),ON(1).
	*
	* @param digital_bandw_ch1 Digital filter bandwidth channel 1.
	*
	* @param gain_dB_ch0 Input TX gain channel 0 [0,60] dB.
	*
	* @param gain_dB_ch1 Input TX gain channel 1 [0,60] dB.
	*
	* @param nco_freq_ch0 NCO frequency channel 0 in Hz.
	*
	* @param nco_freq_ch1 NCO frequency channel 1 in Hz.
	* 
	* @param cmix_mode_ch0 CMIX mode channel 0: UPCONVERT(0), DOWNCONVERT(1).
	*
	* @param cmix_mode_ch1 CMIX mode channel 1: UPCONVERT(0), DOWNCONVERT(1).
	* 
	* @return a new limesdr sink block object
	*/
	static sptr make(std::string serial,
			int device_type,
			int chip_mode,
			int channel,
			int file_switch,
			const char *filename,
			double rf_freq,
			double samp_rate,
			size_t oversample,
			int calibration_ch0,
			double calibr_bandw_ch0,
			int calibration_ch1,
			double calibr_bandw_ch1,
			int pa_path_mini,
			int pa_path_ch0,
			int pa_path_ch1,
			int analog_filter_ch0,
			double analog_bandw_ch0,
			int analog_filter_ch1,
			double analog_bandw_ch1,
			int digital_filter_ch0,
			double digital_bandw_ch0,
			int digital_filter_ch1,
			double digital_bandw_ch1,
			int gain_dB_ch0,
			int gain_dB_ch1,
			float nco_freq_ch0,
			float nco_freq_ch1,
			int cmix_mode_ch0,
			int cmix_mode_ch1);
	
	virtual void set_rf_freq(float rf_freq) = 0;
	
	virtual void set_pa_path(int pa_path, int channel) = 0;
	
	virtual void set_nco(float nco_freq, int cmix_mode, int channel) = 0;
	
	virtual void set_analog_filter(int analog_filter, float analog_bandw, int channel) = 0;
	
	virtual void set_digital_filter(int digital_filter, float digital_bandw, int channel) = 0;
	
	virtual void set_gain(int gain_dB, int channel) = 0;
    };
  }
}

#endif

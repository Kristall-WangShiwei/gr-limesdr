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

#ifndef INCLUDED_LIMESDR_SOURCE_IMPL_H
#define INCLUDED_LIMESDR_SOURCE_IMPL_H

#include "common/device_handler.h"
#include <limesdr/source.h>


static const pmt::pmt_t TIME_TAG = pmt::string_to_symbol("rx_time");

namespace gr {
namespace limesdr {
class source_impl : public source {
    private:
    lms_stream_t streamId[2];

    bool stream_analyzer = false;

    int source_block = 1;

    bool add_tag = false;
    uint32_t pktLoss = 0;

    std::string device_string[2] = {"LimeSDR Mini", "LimeNET-Micro"};

    struct constant_data {
        std::string serial;
        int device_number;
        int device_type;
        int channel_mode;
        int channel;
        double samp_rate;
    } stored;

    std::chrono::high_resolution_clock::time_point t1, t2;

    void print_stream_stats(lms_stream_status_t status);

    int add_time_tag(int channel, lms_stream_meta_t meta);

    public:
    source_impl(std::string serial,
                int device_type,
                int channel_mode,
                int file_switch,
                const char* filename,
                double samp_rate,
                size_t oversample);
    ~source_impl();

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);

    bool start(void);

    bool stop(void);

    inline gr::io_signature::sptr args_to_io_signature(int channel_number, int device_number);

    void init_stream(int device_number, int channel, float samp_rate);

    void set_rf_freq(float rf_freq);

    void set_lna_path(int lna_path, int channel);

    void set_nco(float nco_freq, int channel);

    void set_analog_filter(int analog_filter, float analog_bandw, int channel);

    void set_digital_filter(int digital_filter, float digital_bandw, int channel);

    void set_gain(int gain_dB, int channel);

    void calibrate(int calibrate,int channel, double bandw);
};
} // namespace limesdr
} // namespace gr

#endif

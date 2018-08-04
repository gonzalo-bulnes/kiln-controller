Kiln Controller Firmware
========================

This is a [firmware][firmware-wiki] prototype for a kiln controller.

  [firmware-wiki]: https://en.wikipedia.org/wiki/Firmware

> **DISCLAIMER**: This firmware is part of Kiln Controller.
>
> Kiln Controller is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
>
> **Kilns are dangerous**, any may involve **high voltage, currents and temperature**. Be careful, use what you find here at your own risk and please refer to the [license][license] for details. If what you are looking for is a kiln, the [credits][credits] section may inspire you.

  [credits]: #credits
  [license]: #license

Overview
--------

Currently, the code targets an [Arduino microcontroller][arduino] and is entirely contained in:

- the [`KilnController` project][KilnController]
- the [`State`][State] library

  [arduino]: https://arduino.cc
  [KilnController]: ./KilnController
  [State]: ./State

Usage
-----

I use [Arduino Create][arduino-create] to develop this project, you can [preview the project on the Arduino Create platform](https://create.arduino.cc/editor/yctqmbo/bd545448-fb17-4f7c-a501-6af6de8aaee8/preview).

  [arduino-create]: https://create.arduino.cc/

Credits
-------

The user interface of this project may seem familiar; it is greatly inspired in the work of [Paragon Industries L.P.][paragon] (Paragon).

I have no affiliation to [Paragon][paragon], and none of this firmware has been written by them. I am, however, using their [exemplary user manuals][paragon-user-manual] as a source of inspiration.

As far as I can tell, the Paragon team does a great job. Seriously. If you are looking for a kiln, go [check their website][paragon]! That is probably the way to go.

  [paragon]: http://www.paragonweb.com/
  [paragon-user-manual]: http://www.paragonweb.com/files/manuals/IM222_Sentry-Xpress-CF-RH_May2011.pdf

License
-------

    Copyright (C) 2018 Gonzalo Bulnes Guilpain

    This firmware is part of Kiln Controller.

    Kiln Controller is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Kiln Controller is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

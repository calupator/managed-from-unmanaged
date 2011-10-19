using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace Managed.Csharp
{
    [ComVisible(true)]
    [StructLayout(LayoutKind.Sequential)]
    public struct Entity {
        public int id;
        [MarshalAs(UnmanagedType.BStr)]
        public string name;
    }
}

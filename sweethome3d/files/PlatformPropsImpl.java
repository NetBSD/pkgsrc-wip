package jogamp.common.os;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.nio.ShortBuffer;
import java.security.PrivilegedAction;
import java.util.List;

import jogamp.common.Debug;
import jogamp.common.os.elf.ElfHeaderPart1;
import jogamp.common.os.elf.ElfHeaderPart2;
import jogamp.common.os.elf.SectionArmAttributes;

import com.jogamp.common.nio.Buffers;
import com.jogamp.common.os.AndroidVersion;
import com.jogamp.common.os.NativeLibrary;
import com.jogamp.common.os.Platform;
import com.jogamp.common.os.Platform.ABIType;
import com.jogamp.common.os.Platform.CPUFamily;
import com.jogamp.common.os.Platform.CPUType;
import com.jogamp.common.os.Platform.OSType;
import com.jogamp.common.util.SecurityUtil;
import com.jogamp.common.util.VersionNumber;

public abstract class PlatformPropsImpl {
    static final boolean DEBUG = Debug.debug("Platform");

    public static final boolean isCompatible(final CPUType cpu1, final ABIType abi1, final CPUType cpu2, final ABIType abi2) {
        return cpu1.isCompatible(cpu2) && abi1.isCompatible(abi2);
    }

    public static final String OS;
    public static final String OS_lower;
    public static final String OS_VERSION;
    public static final VersionNumber OS_VERSION_NUMBER;
    public static final String ARCH;
    public static final String ARCH_lower;
    public static final String JAVA_VENDOR;
    public static final String JAVA_VENDOR_URL;
    public static final String JAVA_VERSION;
    public static final VersionNumber JAVA_VERSION_NUMBER;
    public static final int JAVA_VERSION_UPDATE;
    public static final String JAVA_VM_NAME;
    public static final String JAVA_RUNTIME_NAME;
    public static final boolean JAVA_SE;
    public static final boolean JAVA_6;
    public static final boolean JAVA_9;
    public static final boolean JAVA_17;
    public static final boolean JAVA_21;
    public static final String NEWLINE;
    public static final boolean LITTLE_ENDIAN;
    public static final CPUType CPU_ARCH;
    public static final ABIType ABI_TYPE;
    public static final OSType OS_TYPE;
    public static final String os_and_arch;
    public static final boolean useDynamicLibraries;

    static {
        final boolean isAndroid = AndroidVersion.isAvailable;
        JAVA_VENDOR = System.getProperty("java.vendor");
        JAVA_VENDOR_URL = System.getProperty("java.vendor.url");
        JAVA_VERSION = System.getProperty("java.version");
        JAVA_VERSION_NUMBER = new VersionNumber(JAVA_VERSION);
        {
           int usIdx = JAVA_VERSION.lastIndexOf("-u");
           int usOff;
           if( 0 < usIdx ) {
               usOff = 2;
           } else {
               usIdx = JAVA_VERSION.lastIndexOf("_");
               usOff = 1;
           }
           if( 0 < usIdx ) {
               final String buildS = PlatformPropsImpl.JAVA_VERSION.substring(usIdx+usOff);
               final VersionNumber update = new VersionNumber(buildS);
               JAVA_VERSION_UPDATE = update.getMajor();
           } else {
               JAVA_VERSION_UPDATE = 0;
           }
        }
        JAVA_VM_NAME = System.getProperty("java.vm.name");
        JAVA_RUNTIME_NAME = getJavaRuntimeNameImpl();
        JAVA_SE = initIsJavaSE();
        if( JAVA_SE ) {
            if( JAVA_VERSION_NUMBER.compareTo(new VersionNumber(21, 0, 0)) >= 0 ) {
                JAVA_21 = true;
                JAVA_17 = true;
                JAVA_9 = true;
                JAVA_6 = true;
            } else if( JAVA_VERSION_NUMBER.compareTo(new VersionNumber(17, 0, 0)) >= 0 ) {
                JAVA_21 = false;
                JAVA_17 = true;
                JAVA_9 = true;
                JAVA_6 = true;
            } else if( JAVA_VERSION_NUMBER.compareTo(new VersionNumber(9, 0, 0)) >= 0 ) {
                JAVA_21 = false;
                JAVA_17 = false;
                JAVA_9 = true;
                JAVA_6 = true;
            } else if( isAndroid || JAVA_VERSION_NUMBER.compareTo(new VersionNumber(1, 6, 0)) >= 0 ) {
                JAVA_21 = false;
                JAVA_17 = false;
                JAVA_9 = false;
                JAVA_6 = true;
            } else {
                JAVA_21 = false;
                JAVA_17 = false;
                JAVA_9 = false;
                JAVA_6 = false;
            }
        } else {
            JAVA_21 = false;
            JAVA_17 = false;
            JAVA_9 = false;
            JAVA_6 = false;
        }
        NEWLINE = System.getProperty("line.separator");

        OS =  System.getProperty("os.name");
        OS_lower = OS.toLowerCase();
        OS_VERSION =  System.getProperty("os.version");
        OS_VERSION_NUMBER = new VersionNumber(OS_VERSION);
        OS_TYPE = getOSTypeImpl(OS_lower, isAndroid);

        final String elfCpuName;
        final CPUType elfCpuType;
        final ABIType elfABIType;
        final int elfLittleEndian;
        final boolean elfValid;
        {
            final String[] _elfCpuName = { null };
            final CPUType[] _elfCpuType = { null };
            final ABIType[] _elfAbiType = { null };
            final int[] _elfLittleEndian = { 0 };
            final boolean[] _elfValid = { false };
            SecurityUtil.doPrivileged(new PrivilegedAction<Object>() {
                @Override
                public Object run() {
                    RandomAccessFile in = null;
                    try {
                        final File file = queryElfFile(OS_TYPE);
                        if(DEBUG) {
                            System.err.println("ELF-1: Using "+file);
                        }
                        in = new RandomAccessFile(file, "r");
                        final ElfHeaderPart1 eh1 = readElfHeaderPart1(OS_TYPE, in);
                        if(DEBUG) {
                            System.err.println("ELF-1: Got "+eh1);
                        }
                        if( null != eh1 ) {
                            final ElfHeaderPart2 eh2 = readElfHeaderPart2(eh1, in);
                            if(DEBUG) {
                                System.err.println("ELF-2: Got "+eh2);
                            }
                            if( null != eh2 ) {
                                _elfCpuName[0] = eh2.cpuName;
                                _elfCpuType[0] = eh2.cpuType;
                                _elfAbiType[0] = eh2.abiType;
                                if( eh1.isLittleEndian() ) {
                                    _elfLittleEndian[0] = 1;
                                } else if( eh1.isBigEndian() ) {
                                    _elfLittleEndian[0] = 2;
                                }
                                _elfValid[0] = true;
                            }
                        }
                    } catch (final Throwable t) {
                        if(DEBUG) {
                            t.printStackTrace();
                        }
                    } finally {
                        if(null != in) {
                            try {
                                in.close();
                            } catch (final IOException e) { }
                        }
                    }
                    return null;
                } });
            elfCpuName = _elfCpuName[0];
            elfCpuType = _elfCpuType[0];
            elfABIType = _elfAbiType[0];
            elfLittleEndian = _elfLittleEndian[0];
            elfValid = _elfValid[0];
            if( DEBUG ) {
                System.err.println("Platform.Elf: valid "+elfValid+", elfCpuName "+elfCpuName+", cpuType "+elfCpuType+", abiType "+elfABIType+", elfLittleEndian "+elfLittleEndian);
            }
        }

        final boolean littleEndian = queryIsLittleEndianImpl();
        if( elfValid ) {
            switch( elfLittleEndian ) {
                case 1:
                    LITTLE_ENDIAN = true;
                    break;
                case 2:
                    LITTLE_ENDIAN = false;
                    break;
                default:
                    LITTLE_ENDIAN = littleEndian;
                    break;
            }
        } else {
            LITTLE_ENDIAN = littleEndian;
        }
        if( DEBUG ) {
            System.err.println("Platform.Endian: test-little "+littleEndian+", elf[valid "+elfValid+", val "+elfLittleEndian+"] -> LITTLE_ENDIAN "+LITTLE_ENDIAN);
        }

        final String propARCH = System.getProperty("os.arch");
        final String propARCH_lower = propARCH.toLowerCase();
        final CPUType propCpuType = CPUType.query(propARCH_lower);
        final ABIType propABIType = ABIType.query(propCpuType, propARCH_lower);
        if( DEBUG ) {
            System.err.println("Platform.Property: ARCH "+propARCH+", CpuType "+propCpuType+", ABIType "+propABIType);
        }

        final int strategy;
        if( isAndroid ) {
            if( DEBUG ) {
                System.err.println("Android: CPU_ABI1 str "+AndroidVersion.CPU_ABI+", CPU_TYPE "+AndroidVersion.CPU_TYPE+", ABI_TYPE "+AndroidVersion.ABI_TYPE);
                System.err.println("Android: CPU_ABI2 str "+AndroidVersion.CPU_ABI2+", CPU_TYPE2 "+AndroidVersion.CPU_TYPE2+", ABI_TYPE2 "+AndroidVersion.ABI_TYPE2);
            }
            if( elfValid ) {
                if( null != AndroidVersion.CPU_TYPE &&
                    isCompatible(elfCpuType, elfABIType, AndroidVersion.CPU_TYPE, AndroidVersion.ABI_TYPE) )
                {
                    ARCH = AndroidVersion.CPU_ABI;
                    ARCH_lower = ARCH;
                    CPU_ARCH = AndroidVersion.CPU_TYPE;
                    strategy = 110;
                } else if( null != AndroidVersion.CPU_TYPE2 &&
                           isCompatible(elfCpuType, elfABIType, AndroidVersion.CPU_TYPE2, AndroidVersion.ABI_TYPE2) )
                {
                    ARCH = AndroidVersion.CPU_ABI2;
                    ARCH_lower = ARCH;
                    CPU_ARCH = AndroidVersion.CPU_TYPE2;
                    strategy = 111;
                } else {
                    ARCH = elfCpuType.toString();
                    ARCH_lower = ARCH.toLowerCase();
                    CPU_ARCH = elfCpuType;
                    strategy = 112;
                }
                ABI_TYPE = elfABIType;
            } else {
                if( AndroidVersion.CPU_TYPE.family == CPUFamily.ARM || AndroidVersion.CPU_TYPE.family == CPUFamily.X86 ||
                    null == AndroidVersion.CPU_TYPE2 ) {
                    ARCH = AndroidVersion.CPU_ABI;
                    ARCH_lower = ARCH;
                    CPU_ARCH = AndroidVersion.CPU_TYPE;
                    ABI_TYPE = AndroidVersion.ABI_TYPE;
                    strategy = 120;
                } else {
                    ARCH = AndroidVersion.CPU_ABI2;
                    ARCH_lower = ARCH;
                    CPU_ARCH = AndroidVersion.CPU_TYPE2;
                    ABI_TYPE = AndroidVersion.ABI_TYPE2;
                    strategy = 121;
                }
            }
        } else {
            if( elfValid ) {
                if( isCompatible(elfCpuType, elfABIType, propCpuType, propABIType) ) {
                    ARCH = propARCH;
                    ARCH_lower = propARCH_lower;
                    CPU_ARCH = propCpuType;
                    ABI_TYPE = propABIType;
                    strategy = 210;
                } else {
                    ARCH = elfCpuName;
                    ARCH_lower = elfCpuName;
                    CPU_ARCH = elfCpuType;
                    ABI_TYPE = elfABIType;
                    strategy = 211;
                }
            } else {
                ARCH = propARCH;
                ARCH_lower = propARCH_lower;
                CPU_ARCH = propCpuType;
                ABI_TYPE = propABIType;
                strategy = 220;
            }
        }
        if( OSType.IOS == OS_TYPE ) {
            useDynamicLibraries = false;
        } else {
            useDynamicLibraries = true;
        }
        if( DEBUG ) {
            System.err.println("Platform.Hard: ARCH "+ARCH+", CPU_ARCH "+CPU_ARCH+", ABI_TYPE "+ABI_TYPE+" - strategy "+strategy+"(isAndroid "+isAndroid+", elfValid "+elfValid+"), useDynLibs "+useDynamicLibraries);
        }
        os_and_arch = getOSAndArch(OS_TYPE, CPU_ARCH, ABI_TYPE, LITTLE_ENDIAN);
    }

    protected PlatformPropsImpl() {}

    private static final String getJavaRuntimeNameImpl() {
        return SecurityUtil.doPrivileged(new PrivilegedAction<String>() {
            @Override
            public String run() {
              return System.getProperty("java.runtime.name");
            }
          });
    }

    private static final boolean initIsJavaSE() {
        if( null != JAVA_RUNTIME_NAME && JAVA_RUNTIME_NAME.indexOf("Java SE") != -1) {
            return true;
        }
        try {
            Class.forName("java.nio.LongBuffer");
            Class.forName("java.nio.DoubleBuffer");
            return true;
        } catch(final ClassNotFoundException ex) {
        }
        return false;
    }

    private static final boolean queryIsLittleEndianImpl() {
        final ByteBuffer tst_b = Buffers.newDirectByteBuffer(Buffers.SIZEOF_INT);
        final IntBuffer tst_i = tst_b.asIntBuffer();
        final ShortBuffer tst_s = tst_b.asShortBuffer();
        tst_i.put(0, 0x0A0B0C0D);
        return 0x0C0D == tst_s.get(0);
    }

    @SuppressWarnings("unused")
    private static final boolean contains(final String data, final String[] search) {
        if(null != data && null != search) {
            for(int i=0; i<search.length; i++) {
                if(data.indexOf(search[i]) >= 0) {
                    return true;
                }
            }
        }
        return false;
    }

    private static final File queryElfFile(final OSType osType) {
        File file = null;
        try {
            if( OSType.ANDROID == osType ) {
                file = new File(NativeLibrary.findLibrary("gluegen_rt", PlatformPropsImpl.class.getClassLoader()));
            } else {
                if( OSType.LINUX == osType ) {
                    file = new File("/proc/self/exe");
                    if( !checkFileReadAccess(file) ) {
                        file = null;
                    }
                }
                if( null == file ) {
                    file = findSysLib("java");
                }
                if( null == file ) {
                    file = findSysLib("jvm");
                }
            }
        } catch(final Throwable t) {
            if(DEBUG) {
                t.printStackTrace();
            }
        }
        return file;
    }
    private static final ElfHeaderPart1 readElfHeaderPart1(final OSType osType, final RandomAccessFile in) {
        ElfHeaderPart1 res = null;
        try {
            res = ElfHeaderPart1.read(osType, in);
        } catch(final Throwable t) {
            if(DEBUG) {
                System.err.println("Caught: "+t.getMessage());
                t.printStackTrace();
            }
        }
        return res;
    }
    private static final ElfHeaderPart2 readElfHeaderPart2(final ElfHeaderPart1 eh1, final RandomAccessFile in) {
        ElfHeaderPart2 res = null;
        try {
            res = ElfHeaderPart2.read(eh1, in);
        } catch(final Throwable t) {
            if(DEBUG) {
                System.err.println("Caught: "+t.getMessage());
                t.printStackTrace();
            }
        }
        return res;
    }
    private static boolean checkFileReadAccess(final File file) {
        try {
            return file.isFile() && file.canRead();
        } catch (final Throwable t) { }
        return false;
    }
    private static File findSysLib(final String libName) {
        final ClassLoader cl = PlatformPropsImpl.class.getClassLoader();
        final List<String> possibleLibPaths = NativeLibrary.enumerateLibraryPaths(libName, libName, libName, true, cl);
        for(int i=0; i<possibleLibPaths.size(); i++) {
            final String libPath = possibleLibPaths.get(i);
            final File lib = new File(libPath);
            if(DEBUG) {
                System.err.println("findSysLib #"+i+": test "+lib);
            }
            if( checkFileReadAccess(lib) ) {
                return lib;
            }
            if(DEBUG) {
                System.err.println("findSysLib #"+i+": "+lib+" not readable");
            }
        }
        return null;
    }

    private static final OSType getOSTypeImpl(final String osLower, final boolean isAndroid) throws RuntimeException {
        if ( isAndroid ) {
            return OSType.ANDROID;
        }
        if ( osLower.startsWith("linux") ) {
            return OSType.LINUX;
        }
        if ( osLower.startsWith("freebsd") ) {
            return OSType.FREEBSD;
        }
        if ( osLower.startsWith("netbsd") ) {
            return OSType.LINUX;
        }
        if ( osLower.startsWith("android") ) {
            return OSType.ANDROID;
        }
        if ( osLower.startsWith("mac os x") ||
             osLower.startsWith("darwin") ) {
            return OSType.MACOS;
        }
        if ( osLower.startsWith("sunos") ) {
            return OSType.SUNOS;
        }
        if ( osLower.startsWith("hp-ux") ) {
            return OSType.HPUX;
        }
        if ( osLower.startsWith("windows") ) {
            return OSType.WINDOWS;
        }
        if ( osLower.startsWith("kd") ) {
            return OSType.OPENKODE;
        }
        if ( osLower.startsWith("ios") ) {
            return OSType.IOS;
        }
        throw new RuntimeException("Please port OS detection to your platform (" + OS_lower + "/" + ARCH_lower + ")");
    }

    public static void initSingleton() { }

    public static final String getOSAndArch(final OSType osType, final CPUType cpuType, final ABIType abiType, final boolean littleEndian) {
        final String os_;
        final String _and_arch_tmp, _and_arch_final;

        switch( cpuType ) {
            case ARM:
            case ARMv5:
            case ARMv6:
            case ARMv7:
                if( ABIType.EABI_GNU_ARMHF == abiType ) {
                    _and_arch_tmp = "armv6hf";
                } else {
                    _and_arch_tmp = "armv6";
                }
                break;
            case X86_32:
                _and_arch_tmp = "i586";
                break;
            case PPC:
                _and_arch_tmp = "ppc";
                break;
            case MIPS_32:
                _and_arch_tmp = littleEndian ? "mipsel" : "mips";
                break;
            case SuperH:
                _and_arch_tmp = "superh";
                break;
            case SPARC_32:
                _and_arch_tmp = "sparc";
                break;
            case ARM64:
            case ARMv8_A:
                _and_arch_tmp = "aarch64";
                break;
            case X86_64:
                _and_arch_tmp = "amd64";
                break;
            case PPC64:
                _and_arch_tmp = littleEndian ? "ppc64le" : "ppc64";
                break;
            case MIPS_64:
                _and_arch_tmp = "mips64";
                break;
            case IA64:
                _and_arch_tmp = "ia64";
                break;
            case SPARCV9_64:
                _and_arch_tmp = "sparcv9";
                break;
            case PA_RISC2_0:
                _and_arch_tmp = "risc2.0";
                break;
            default:
                throw new InternalError("Unhandled CPUType: "+cpuType);
        }

        switch( osType ) {
            case ANDROID:
              os_ = "android";
              _and_arch_final = _and_arch_tmp;
              break;
            case MACOS:
              os_ = "macosx";
              _and_arch_final = "universal";
              break;
            case IOS:
              os_ = "ios";
              _and_arch_final = _and_arch_tmp;
              break;
            case WINDOWS:
              os_ = "windows";
              _and_arch_final = _and_arch_tmp;
              break;
            case OPENKODE:
              os_ = "openkode";
              _and_arch_final = _and_arch_tmp;
              break;
            case LINUX:
              os_ = "linux";
              _and_arch_final = _and_arch_tmp;
              break;
            case FREEBSD:
              os_ = "freebsd";
              _and_arch_final = _and_arch_tmp;
              break;
            case SUNOS:
              os_ = "solaris";
              _and_arch_final = _and_arch_tmp;
              break;
            case HPUX:
              os_ = "hpux";
              _and_arch_final = "hppa";
              break;
            default:
              throw new InternalError("Unhandled OSType: "+osType);
        }
        return os_ + "-" + _and_arch_final;
    }

}

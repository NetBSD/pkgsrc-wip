# $NetBSD: buildlink2.mk,v 1.3 2003/11/29 20:04:22 mpasternak Exp $
#
# This Makefile fragment is included by packages that use mingw-w32api-bin.

.if !defined(MINGW_W32API_BIN_BUILDLINK2_MK)
MINGW_W32API_BIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mingw-w32api-bin
BUILDLINK_DEPENDS.mingw-w32api-bin?=		mingw-w32api-bin>=2.4
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=		../../wip/mingw-w32api-bin

EVAL_PREFIX+=	BUILDLINK_PREFIX.mingw-w32api-bin=mingw-w32api-bin
BUILDLINK_PREFIX.mingw-w32api-bin_DEFAULT=	${CROSSBASE}/i586-mingw

BUILDLINK_FILES.mingw-w32api-bin= \
	include/accctrl.h include/aclapi.h include/basetsd.h \
	include/basetyps.h include/cderr.h include/cguid.h include/comcat.h \
	include/commctrl.h include/commdlg.h include/cpl.h include/cplext.h \
	include/custcntl.h include/dbt.h include/dde.h include/ddeml.h \
	include/ddk/atm.h include/ddk/batclass.h include/ddk/cfg.h \
	include/ddk/cfgmgr32.h include/ddk/d4drvif.h include/ddk/d4iface.h \
	include/ddk/ddkmapi.h include/ddk/hidclass.h include/ddk/hidpi.h \
	include/ddk/hidusage.h include/ddk/mcd.h include/ddk/miniport.h \
	include/ddk/minitape.h include/ddk/mountdev.h include/ddk/mountmgr.h \
	include/ddk/ndis.h include/ddk/ndisguid.h include/ddk/ndistapi.h \
	include/ddk/ndiswan.h include/ddk/netevent.h include/ddk/netpnp.h \
	include/ddk/newdev.h include/ddk/ntapi.h include/ddk/ntdd8042.h \
	include/ddk/ntddbeep.h include/ddk/ntddcdrm.h include/ddk/ntddcdvd.h \
	include/ddk/ntddchgr.h include/ddk/ntdddisk.h include/ddk/ntddk.h \
	include/ddk/ntddkbd.h include/ddk/ntddmou.h include/ddk/ntddndis.h \
	include/ddk/ntddpar.h include/ddk/ntddpcm.h include/ddk/ntddscsi.h \
	include/ddk/ntddser.h include/ddk/ntddstor.h include/ddk/ntddtape.h \
	include/ddk/ntddtdi.h include/ddk/ntddvdeo.h include/ddk/ntddvol.h \
	include/ddk/ntifs.h include/ddk/ntpoapi.h include/ddk/ntstatus.h \
	include/ddk/parallel.h include/ddk/pfhook.h include/ddk/poclass.h \
	include/ddk/scsi.h include/ddk/scsiscan.h include/ddk/scsiwmi.h \
	include/ddk/smbus.h include/ddk/srb.h include/ddk/storport.h \
	include/ddk/tdi.h include/ddk/tdiinfo.h include/ddk/tdikrnl.h \
	include/ddk/tdistat.h include/ddk/tvout.h include/ddk/upssvc.h \
	include/ddk/usb.h include/ddk/usb100.h include/ddk/usbcamdi.h \
	include/ddk/usbdi.h include/ddk/usbioctl.h include/ddk/usbiodef.h \
	include/ddk/usbscan.h include/ddk/usbuser.h include/ddk/video.h \
	include/ddk/videoagp.h include/ddk/win2k.h include/ddk/winddi.h \
	include/ddk/winddk.h include/ddk/winnt4.h include/ddk/winxp.h \
	include/ddk/ws2san.h include/ddk/xfilter.h include/dlgs.h \
	include/docobj.h include/exdisp.h include/exdispid.h include/GL/gl.h \
	include/GL/glext.h include/GL/glu.h include/httpext.h \
	include/idispids.h include/imagehlp.h include/imm.h \
	include/initguid.h include/lm.h include/intshcut.h \
	include/ipexport.h include/iphlpapi.h include/ipifcons.h \
	include/iprtrmib.h include/iptypes.h include/isguids.h \
	include/largeint.h include/lmaccess.h include/lmalert.h \
	include/lmapibuf.h include/lmat.h include/lmaudit.h \
	include/lmbrowsr.h include/lmchdev.h include/lmconfig.h \
	include/lmcons.h include/lmerr.h include/lmerrlog.h include/lmmsg.h \
	include/lmremutl.h include/lmrepl.h include/lmserver.h \
	include/lmshare.h include/lmsname.h include/lmstats.h \
	include/lmsvc.h include/lmuse.h include/lmuseflg.h include/lmwksta.h \
	include/lzexpand.h include/mapi.h include/mciavi.h include/mcx.h \
	include/mgmtapi.h include/mmsystem.h include/mshtml.h \
	include/mswsock.h include/nb30.h include/nddeapi.h include/nspapi.h \
	include/ntdef.h include/ntdll.h include/ntldap.h include/ntsecapi.h \
	include/ntsecpkg.h include/oaidl.h include/objbase.h \
	include/objfwd.h include/objidl.h include/ocidl.h include/odbcinst.h \
	include/ole.h include/ole2.h include/ole2ver.h include/oleacc.h \
	include/oleauto.h include/olectl.h include/olectlid.h \
	include/oledlg.h include/oleidl.h include/pbt.h include/poppack.h \
	include/powrprof.h include/prsht.h include/psapi.h \
	include/pshpack1.h include/pshpack2.h include/pshpack4.h \
	include/pshpack8.h include/rapi.h include/ras.h include/rasdlg.h \
	include/raserror.h include/rassapi.h include/regstr.h \
	include/richedit.h include/richole.h include/rpc.h include/rpcdce.h \
	include/rpcdce2.h include/rpcdcep.h include/rpcndr.h \
	include/rpcnsi.h include/rpcnsip.h include/rpcnterr.h \
	include/rpcproxy.h include/schannel.h include/schnlsp.h \
	include/scrnsave.h include/secext.h include/security.h \
	include/servprov.h include/setupapi.h include/shellapi.h \
	include/shlguid.h include/shlobj.h include/shlwapi.h include/snmp.h \
	include/sql.h include/sqlext.h include/sqltypes.h include/sqlucode.h \
	include/sspi.h include/subauth.h include/svcguid.h \
	include/tlhelp32.h include/unknwn.h include/userenv.h include/vfw.h \
	include/w32api.h include/winable.h include/winbase.h \
	include/winber.h include/wincon.h include/wincrypt.h \
	include/windef.h include/windows.h include/windowsx.h \
	include/winerror.h include/wingdi.h include/wininet.h \
	include/winioctl.h include/winldap.h include/winnetwk.h \
	include/winnls.h include/winnt.h include/winperf.h include/winreg.h \
	include/winresrc.h include/winsnmp.h include/winsock.h \
	include/winsock2.h include/winspool.h include/winsvc.h \
	include/winuser.h include/winver.h include/ws2spi.h \
	include/ws2tcpip.h include/wsahelp.h include/wsipx.h \
	include/wsnetbs.h include/wtypes.h include/zmouse.h \
	lib/libadvapi32.a lib/libapcups.a lib/libcap.a lib/libcfgmgr32.a \
	lib/libcomctl32.a lib/libcomdlg32.a lib/libcrypt32.a \
	lib/libctl3d32.a lib/libd3dim.a lib/libd3drm.a lib/libd3dxof.a \
	lib/libddraw.a lib/libdinput.a lib/libdlcapi.a lib/libdplayx.a \
	lib/libdsetup.a lib/libdsound.a lib/libdxapi.a lib/libdxguid.a \
	lib/libgdi32.a lib/libglaux.a lib/libglu32.a lib/libglut.a \
	lib/libglut32.a lib/libhal.a lib/libhid.a lib/libhidparse.a \
	lib/libigmpagnt.a lib/libimagehlp.a lib/libimm32.a lib/libiphlpapi.a \
	lib/libkernel32.a lib/liblargeint.a lib/liblz32.a lib/libmapi32.a \
	lib/libmcd.a lib/libmfcuia32.a lib/libmgmtapi.a lib/libmpr.a \
	lib/libmsacm32.a lib/libmsimg32.a lib/libmsvcp60.a lib/libmswsock.a \
	lib/libnddeapi.a lib/libndis.a lib/libntdll.a lib/libnetapi32.a \
	lib/libntoskrnl.a lib/libodbc32.a lib/libodbccp32.a lib/libole32.a \
	lib/liboleacc.a lib/liboleaut32.a lib/libolecli32.a lib/liboledlg.a \
	lib/libolepro32.a lib/libolesvr32.a lib/libopengl32.a \
	lib/libpenwin32.a lib/libpkpd32.a lib/libpowrprof.a lib/libpsapi.a \
	lib/librapi.a lib/librasapi32.a lib/librasdlg.a lib/librpcdce4.a \
	lib/librpcns4.a lib/librpcrt4.a lib/libscrnsave.a lib/libscrnsavw.a \
	lib/libscsiport.a lib/libsecur32.a lib/libsetupapi.a \
	lib/libshell32.a lib/libshfolder.a lib/libshlwapi.a lib/libsnmpapi.a \
	lib/libsvrapi.a lib/libtapi32.a lib/libtdi.a lib/libth32.a \
	lib/libthunk32.a lib/liburl.a lib/libusbcamd.a lib/libusbcamd2.a \
	lib/libuser32.a lib/libuserenv.a lib/libuuid.a lib/libvdmdbg.a \
	lib/libversion.a lib/libvfw32.a lib/libwin32k.a lib/libvideoprt.a \
	lib/libwin32spl.a lib/libwininet.a lib/libwinmm.a lib/libwinspool.a \
	lib/libwinstrm.a lib/libwldap32.a lib/libwow32.a lib/libws2_32.a \
	lib/libwsnmp32.a lib/libwsock32.a lib/libwst.a 


BUILDLINK_TARGETS+=	mingw-w32api-bin-buildlink

mingw-w32api-bin-buildlink: _BUILDLINK_USE

.endif	# MINGW_W32API_BIN_BUILDLINK2_MK

# $NetBSD: Makefile,v 1.12 2004/08/31 16:27:25 lexort Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	quagga-0.96.5-20040831
PKGNAME=	quagga-0.96.5.20040831
#PKGREVISION=	0
CATEGORIES=	net
# Use pkgsrc/ for saved snapshots, cvs/ for current ones
MASTER_SITES=	http://www.quagga.net/download/cvs/ \
		http://www.ir.bbn.com/~gdt/pkgsrc-wip/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.quagga.net/
COMMENT=	Free multithreaded routing daemon software (fork of zebra)

WRKSRC=		${WRKDIR}/quagga-0.96.5

.include "../../mk/bsd.prefs.mk"

AUTOMAKE_REQD=		1.6
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		YES
LIBTOOL_LA_FILES+=	lib/libospf.la
LIBTOOL_LA_FILES+=	lib/libzebra.la

PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-exampledir=${PREFIX}/share/examples/quagga
# Note that localstatedir is wired into the rc.d scripts.
CONFIGURE_ARGS+=	--localstatedir=/var/run/zebra
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

CONFLICTS+=		zebra-[0-9]*
CONFLICTS+=		quagga-[0-9]*

PLIST_SRC=      ${WRKDIR}/PLIST
PLIST_CAT=	# empty

INFO_FILES=	quagga.info

USE_PKGINSTALL=	YES
RCD_SCRIPTS=	zebra bgpd ospfd ripd
PKG_GROUPS=	quagga
PKG_USERS=	quagga:quagga

.for _file_ in vtysh.conf zebra.conf bgpd.conf ospfd.conf ripd.conf
CONF_FILES_PERMS+=      ${PREFIX}/share/examples/quagga/log_syslog.conf ${PKG_SYSCONFDIR}/${_file_} quagga quagga 0600
.endfor
.undef _file_

BUILD_DEFS+=			USE_ZEBRA_VTYSH USE_ZEBRA_OSPF_OPAQUELSA
USE_ZEBRA_VTYSH?=		YES
USE_ZEBRA_OSPF_OPAQUELSA?=	NO

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_CAT+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

.if defined(USE_ZEBRA_OSPF_OPAQUELSA) && ${USE_ZEBRA_OSPF_OPAQUELSA} == "YES"
CONFIGURE_ARGS+=	--enable-opaque-lsa
PLIST_CAT+=		${PKGDIR}/PLIST.opaquelsa
.endif

USE_GNU_TOOLS+=		make

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
PLIST_CAT+=		${PKGDIR}/PLIST.v6
RCD_SCRIPTS+=		ospf6d ripngd
.for _file_ in ospf6d.conf ripngd.conf
CONF_FILES_PERMS+=      ${PREFIX}/share/examples/quagga/log_syslog.conf ${PKG_SYSCONFDIR}/${_file_} quagga quagga 0600
.endfor
.undef _file_
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

PLIST_CAT+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

.for _script_ in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${_script_}?=	${WRKSRC}/pkgsrc/${_script_}.sh
.endfor

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} --force

post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/quagga/*
	${INSTALL} -d -o quagga -g quagga -m 750 ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${FILESDIR}/log_syslog.conf ${PREFIX}/share/examples/quagga
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quagga
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quagga/mpls
	${INSTALL_DATA} ${WRKSRC}/doc/BGP-TypeCode ${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/draft-zebra-00.txt ${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/mpls/* ${PREFIX}/share/doc/quagga/mpls
	${CAT} ${PLIST_CAT} > ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/quagga -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/quagga -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}
#	cd ${PREFIX}/info ; \
#	for t in "" -1 -2 -3 -4; do mv quagga.info$$t quagga$$t; done

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2004/05/11 04:29:39 blef Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp

DISTNAME=	zebra-pj-20030428
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zebra.dishone.st/snapshots/pkgsrc/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://zebra.dishone.st/
COMMENT=	Free multithreaded routing daemon software

CONFLICTS=		zebra

AUTOCONF_REQD=		2.13
AUTOMAKE_REQD=		1.4
GNU_CONFIGURE=		# defined
USE_GNU_TOOLS+=		make
INFO_FILES=	zebra.info zebra.info-1 zebra.info-2 \
		zebra.info-3 zebra.info-4

# for INET6
.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# zebra control socket, vtysh
CONFIGURE_ARGS+=	--localstatedir=/var/run

PLIST_SRC=		# empty (built from optional pieces below)

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_BUILDLINK3=		yes
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_SRC+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

BUILD_DEFS+=		USE_INET6
.if defined(USE_INET6) && ${USE_INET6} == YES
PLIST_SRC+=		${PKGDIR}/PLIST.v6
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

# patches modify Makefile.am and configure.in
pre-configure:
	cd ${WRKSRC};						\
	${ACLOCAL};						\
	${AUTOHEADER};						\
	${AUTOMAKE} -a --foreign -i;				\
	${AUTOCONF}

# Makefile.am in zebra-pj install examples 0600 for no apparent reason.
post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"

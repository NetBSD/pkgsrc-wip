# $NetBSD: Makefile,v 1.4 2004/05/08 19:07:05 blef Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	quagga-0.96.4-20031223
PKGNAME=	quagga-0.96.4.20031223
WRKSRC=		${WRKDIR}/quagga-0.96.4
CATEGORIES=	net
# Use pkgsrc/ for saved snapshots, cvs/ for current ones
MASTER_SITES=	http://www.quagga.net/download/pkgsrc/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.quagga.net/
COMMENT=	Free multithreaded routing daemon software (fork of zebra)

.include "../../mk/bsd.prefs.mk"

AUTOMAKE_REQD=		1.6.2
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-exampledir=${PREFIX}/share/examples/quagga
CONFIGURE_ARGS+=	--localstatedir=/var/run/zebra
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

CONFLICTS+=		zebra-[0-9]*
CONFLICTS+=		quagga-[0-9]*

PLIST_SRC=		# empty

INFO_FILES=	quagga.info

USE_PKGINSTALL=	YES
PKG_GROUPS=	quagga
PKG_USERS=	quagga:quagga

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_SRC+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

USE_GNU_TOOLS+=		make

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
PLIST_SRC+=		${PKGDIR}/PLIST.v6
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} --force
	cd ${WRKSRC} && ${AUTOMAKE}

post-install:
	@${MKDIR} /var/run/zebra
	@${CHOWN} quagga:quagga /var/run/zebra

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"

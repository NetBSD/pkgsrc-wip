# $NetBSD: Makefile,v 1.13 2005/06/08 15:42:57 dillo Exp $
#

DISTNAME=		firebird-1.5.0.4290
PKGNAME=		${DISTNAME:S/.4290//}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=firebird/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://firebird.sf.net/
COMMENT=		SQL database, opensource version of InterBase

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PREFIX=			${LOCALBASE}/firebird15

CONFIGURE_ARGS+=	--with-lock-manager
CONFIGURE_ARGS+=	--with-editline

# Yes, such versions are required, you won't build this package without
# those:
AUTOCONF_REQD=		2.53
GCC_REQD=		3.3.0
USE_TOOLS+=		gm4 		# needs GNU M4 version 4.14
USE_TOOLS+=		automake

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		./autogen.sh ${CONFIGURE_ARGS}

.include "../../mk/bsd.pkg.mk"

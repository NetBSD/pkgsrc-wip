# $NetBSD: Makefile,v 1.3 2004/01/02 22:07:46 mpasternak Exp $
#

# A few words about DISTFILE:
#
# DISTFILE included it *NOT* an official firebird.sf.net source code release.
# 
# As Firebird-1.5 sources are unavailable via direct download from SF.net (it
# is only possible to do cvs checkout), FreeBSD's port maintainer -- Chris
# Knight <chris(at)e-easy(dot)com(dot)au> -- created a downloadable .tar.bz2
# file as a checkout of 1.5RC8 tag. I have contacted him; he will be trying to
# put that DISTFILE on SF.net page . As FreeBSD Ports use the same sources, I
# think we can trust them. FreeBSD package was commited to FreeBSD Ports
# repository by developer netchild(at)freebsd(dot)org
#
# I think, that in near future either Chris will put the sources on SF.net, or
# some trusted NetBSD developer will be able to do source checkout and put the
# tarball somewhere on NetBSD site.

DISTNAME=		firebird15-rc8
PKGNAME=		${DISTNAME:S/-rc8//}
CATEGORIES=		databases
MASTER_SITES=		http://www.aims.net.au/chris/firebird/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://firebird.sf.net/
COMMENT=		SQL database, opensource version of InterBase

WRKSRC=			${WRKDIR}/firebird15
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
PREFIX=			${LOCALBASE}/firebird15

CONFIGURE_ARGS+=	--with-lock-manager 
CONFIGURE_ARGS+=	--with-editline
CONFIGURE_ENV+=		AUTOCONF=${AUTOCONF}
CONFIGURE_ENV+=		AUTOMAKE=${AUTOMAKE}

# Yes, such versions are required, you won't build this package without
# those:
AUTOCONF_REQD=		2.53
GCC_REQD=		3.3.0
USE_GNU_TOOLS+=		m4 		# needs GNU M4 version 4.14

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		./autogen.sh ${CONFIGURE_ARGS}

.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"

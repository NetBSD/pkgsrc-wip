# $NetBSD: Makefile,v 1.12 2010/01/18 09:38:25 thomasklausner Exp $

VERS=		4.4.0
PKGNAME=	hylafax-devel-${VERS}
DISTNAME=	hylafax-${VERS}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES_BETA=	ftp://ftp.hylafax.org/source/BETA/
MASTER_SITES_RELEASE=	ftp://ftp.hylafax.org/source/

.if empty(VERS:M[0-9].[0-9].[0-9]rc[0-9])
MASTER_SITES=	${MASTER_SITES_RELEASE}
.else
MASTER_SITES=	${MASTER_SITES_BETA}
.endif

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system

DEPENDS+=	mawk>=1.2.2:../../lang/mawk

DIST_SUBDIR=	hylafax

CONFLICTS=	hylafax-[0-9]* mgetty-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gs:run
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-MAKE=${MAKE_PROGRAM:Q}
CONFIGURE_ARGS+=	--with-INSTALL="" --nointeractive
CONFIGURE_ARGS+=	--with-ZLIBINC=-I${BUILDLINK_PREFIX.zlib:Q}/include
CONFIGURE_ARGS+=	--with-LIBZ="-L${BUILDLINK_PREFIX.zlib}/lib -lz"
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q} OPTIMIZER=${CFLAGS:M*:Q}
CONFIGURE_ENV+=		FAXUID=${FAXUSER:Q} FAXGID=${FAXGROUP:Q}
MANCOMPRESSED=		yes

.include "../../mk/bsd.prefs.mk"

FAXUSER?=	uucp
FAXGROUP?=	dialer
RCD_SCRIPTS=	hylafax

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

INSTALLATION_DIRS = libdata

PKG_OPTIONS_VAR=	PKG_OPTIONS.hylafax
PKG_SUPPORTED_OPTIONS=	pam
######################################################
# pam doesn't work right now, so disabled by default #
######################################################
#PKG_SUGGESTED_OPTIONS=       pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

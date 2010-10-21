# $NetBSD: Makefile,v 1.9 2010/10/21 08:13:50 makoto Exp $

VERS=		4.4.7
DISTNAME=	hylafax-${VERS}
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

PKG_DESTDIR_SUPPORT=	user-destdir
DIST_SUBDIR=	hylafax

CONFLICTS=	hylafax-devel-[0-9]* mgetty-[0-9]*

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

PKG_GROUPS=	${FAXGROUP}
PKG_USERS=	${FAXUSER}:${FAXGROUP}
PKG_GECOS.uucp=	Unix to Unix Copy Program

SETUID_UUCP_PERMS=	${FAXUSER} ${FAXGROUP} 4555

SPECIAL_PERMS+=	libexec/faxgetty ${SETUID_UUCP_PERMS} \
		sbin/faxq ${SETUID_UUCP_PERMS} \
		bin/faxrm ${SETUID_UUCP_PERMS} \
		bin/faxalter ${SETUID_UUCP_PERMS}

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

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

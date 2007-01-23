# $NetBSD: Makefile,v 1.2 2007/01/23 19:11:20 cheusov Exp $

DISTNAME=		xmms-skins_0.5.orig
PKGNAME=		xmms-skins-0.5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/x/xmms-skins/}

MAINTAINER=		cheusov@tut.by
# I don't know where it is real home page of xmms-skins
HOMEPAGE=		http://www.debian.org/
COMMENT=		Skins for XMMS

DEPENDS+=		xmms>=1.2.0:../../audio/xmms

NO_CONFIGURE=		yes

XMMS_SKINS_VERSION=	${PKGNAME:S/xmms-skins-//1}

WRKSRC=			${WRKDIR}/xmms-skins-${XMMS_SKINS_VERSION}.orig

DOC_FILES=		AUTHORS COPYING ChangeLog README
SKIN_FILES=		Absolute-Blue.tar.gz Cherry-Best.tar.gz \
			Cobalt.tar.gz Colder.tar.gz Eclipse.tar.gz \
			FB2.tar.gz Helix-Sawfish.tar.gz Plume.tar.gz \
			SpiffMedia.tar.gz Titanium.tar.gz minEguE.tar.gz

DOC_DIR=		${PREFIX}/share/doc/xmms-skins
SKIN_DIR=		${PREFIX}/share/xmms/Skins

INSTALLATION_DIRS+=	${DOC_DIR} ${SKIN_DIR}

do-build:

do-install:
	set -e;                                                 \
	for i in ${DOC_FILES}; do                               \
		${INSTALL_DATA} ${WRKSRC}/"$$i" ${DOC_DIR};       \
	done;                                                   \
	for i in ${SKIN_FILES}; do                              \
		${INSTALL_DATA} ${WRKSRC}/Skins/"$$i" ${SKIN_DIR};\
	done

.include "../../mk/bsd.pkg.mk"

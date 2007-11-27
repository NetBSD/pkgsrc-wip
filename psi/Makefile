# $NetBSD: Makefile,v 1.2 2007/11/27 20:42:14 schnoebe Exp $

PSI_VERSION=	0.11
DISTNAME=	psi-${PSI_VERSION}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi-im.org/
COMMENT=	PSI Jabber Client

DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANG_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-zlib-inc=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-lib=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-aspell-inc=${BUILDLINK_PREFIX.aspell}/include
CONFIGURE_ARGS+=	--with-aspell-lib=${BUILDLINK_PREFIX.aspell}/lib
CONFIGURE_ARGS+=	--with-openssl-inc=${BUILDLINK_PREFIX.openssl}/include
CONFIGURE_ARGS+=	--with-openssl-lib=${BUILDLINK_PREFIX.openssl}/lib



#
# LANG_FILES left for when the translations get released in a few weeks
#	the PLIST will also need to be updated at that time.
#
# LANG_FILES=	psi_bg.qm psi_ca.qm psi_eo.qm psi_es.qm psi_fr.qm	\
# 		psi_hu.qm psi_mk.qm psi_nl.qm psi_pl.qm psi_pt.qm	\
# 		psi_pt_BR.qm psi_sk.qm psi_sl.qm psi_vi.qm psi_zh.qm
LANG_FILES= psi_ru.qm

.for l in ${LANG_FILES}
SITES.${l}=	http://psi-im.org/files/translation/${PSI_VERSION}/
.endfor

INSTALLATION_DIRS=	bin share/psi share/doc/psi

post-install:
	# install the translations
.for f in ${LANG_FILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${PREFIX}/share/psi
.endfor

.include "../../textproc/aspell/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.3.2
.include "../../x11/qt4-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.3.2
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2008/07/30 00:42:49 schnoebe Exp $

PSI_VERSION=	0.12
DISTNAME=	psi-${PSI_VERSION}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://psi-im.org/
COMMENT=	PSI Jabber Client

DEPENDS+=	qca2-ossl>=2.0.0beta3:../../security/qca2-ossl

DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DEFAULT_DISTFILES} ${LANG_FILES}
EXTRACT_ONLY=	${DEFAULT_DISTFILES}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--disable-bundled-qca
CONFIGURE_ARGS+=	--with-zlib-inc=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-lib=${BUILDLINK_PREFIX.zlib}/lib

#
# LANG_FILES left for when the translations get released in a few weeks
#	the PLIST will also need to be updated at that time.
#
# LANG_FILES=	psi_bg.qm psi_ca.qm psi_eo.qm psi_es.qm psi_fr.qm	\
# 		psi_hu.qm psi_mk.qm psi_nl.qm psi_pl.qm psi_pt.qm	\
# 		psi_pt_BR.qm psi_sk.qm psi_sl.qm psi_vi.qm psi_zh.qm
LANG_FILES=     psi_pt_BR.qm psi_cs.qm psi_de.qm psi_es_ES.qm psi_fr.qm \
                psi_mk.qm psi_pl.qm psi_ru.qm psi_uk.qm psi_vi.qm psi_zh.qm

.for l in ${LANG_FILES}
SITES.${l}=	http://psi-im.org/download/lang/
.endfor

INSTALLATION_DIRS=	bin share/psi share/doc/psi

.include "options.mk"

post-install:
	# remove some files that shouldn't be there,
	# install some files where they should be installed
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/psi
	${RM} ${PREFIX}/share/psi/README
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/psi
	${RM} ${PREFIX}/share/psi/COPYING
	# install the translations
.for f in ${LANG_FILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${PREFIX}/share/psi
.endfor

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.3.2
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

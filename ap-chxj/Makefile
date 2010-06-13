# $NetBSD: Makefile,v 1.6 2010/06/13 22:46:56 thomasklausner Exp $
#

DISTNAME=	mod-chxj_0.12.12.src
PKGNAME=	${APACHE_PKG_PREFIX}-${DISTNAME:S/mod-//:S/_/-/:S/.src//}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=modchxj/32266/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/modchxj/wiki/FrontPage
COMMENT=	CHTML to HDML,XHTML,JHTML convert module for apache2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}

PKG_APACHE_ACCEPTED=	apache2 apache22
PKG_SYSCONFSUBDIR=	httpd/chxj

CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-apache-header=${BUILDLINK_PREFIX.apache}/include/httpd
CONFIGURE_ENV+=		ac_cv_path_LIBTOOL=${LIBTOOL:Q}
CONFIGURE_ENV+=		WAND_CONFIG=${BUILDLINK_PREFIX.ImageMagick}/bin/Wand-config
CONFIGURE_ENV+=		APR_CONFIG=${BUILDLINK_DIR}/bin/apr-config
CONFIGURE_ENV+=		APU_CONFIG=${BUILDLINK_DIR}/bin/apu-config

.include "options.mk"

EGDIR=			share/examples/mod_chxj
EGFILES=		device_data.xml emoji.xml
DOCDIR=			share/doc/mod_chxj
DOCS=			modchxj.html

.for f in ${EGFILES}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
.for f in ${EGFILES}
	${INSTALL_DATA}	${WRKSRC}/etc/${f} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"

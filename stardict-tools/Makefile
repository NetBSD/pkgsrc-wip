# $NetBSD: Makefile,v 1.5 2010/01/17 12:03:32 thomasklausner Exp $
#

DISTNAME=	stardict-tools-3.0.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stardict/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://stardict.sourceforge.net/
COMMENT=	StarDict tools for dictionary conversions

LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		aclocal autoheader autoconf automake pkg-config

AUTOCONF_REQD=		2.61

AUTO_MKDIRS=		yes

EXTRA_DOC_FILES=	COPYING NEWS README INSTALL AUTHORS ChangeLog
EXTRA_DIR=		${PREFIX}/share/doc/stardict-tools

EGFILES=		example.ifo
EGDIR=			${PREFIX}/share/examples/stardict-tools

pre-configure:
	set -e; \
	cp ${.CURDIR}/files/*.c ${WRKSRC}/src/; \
	cd ${WRKSRC} && aclocal && autoheader && autoconf && automake

post-install:
	set -e; cd ${WRKSRC}/src; \
	sd_tools=`grep noinst_PROGRAMS Makefile.am | cut -d= -f2`; \
	for i in $${sd_tools}; do \
		cp "$${i}" ${DESTDIR}${PREFIX}/bin/stardict-"$${i}"; \
	done; \
	${INSTALL_DATA} ${EGFILES} ${DESTDIR}${EGDIR}; \
	cd ..; \
	${INSTALL_DATA} ${EXTRA_DOC_FILES} ${DESTDIR}${EXTRA_DIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

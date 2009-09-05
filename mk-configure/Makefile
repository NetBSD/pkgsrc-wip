# $NetBSD: Makefile,v 1.11 2009/09/05 14:26:31 cheusov Exp $
#

DISTNAME=	mk-configure-0.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mk-configure/} \
		http://mova.org/~cheusov/pub/mk-configure/

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://sourceforge.net/projects/mk-configure
COMMENT=	Lightweight but powerful replacement for GNU autotools

LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# no languages
USE_BSD_MAKEFILE=	yes

DOC_FILES=		README NEWS ChangeLog TODO FAQ

MAKE_ENV+=		MKCATPAGES=no

AUTO_MKDIRS=		yes

PKGDOCDIR=		share/doc/mk-configure
EGDIR=			share/examples/mk-configure

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor
	cp -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == NetBSD && exists(/usr/pkg/heirloom/bin/posix2001/awk)
REPLACE_INTERPRETER+=   awk
REPLACE.awk.old=        /.*/nawk
REPLACE.awk.new=        /usr/bin/awk
REPLACE_FILES.awk=      mkc_check_version
#.endif

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2010/01/31 19:06:52 cheusov Exp $
#

DISTNAME=	mk-configure-0.14.0
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

DOC_FILES=		README NEWS ChangeLog TODO FAQ COPYRIGHT

MAKE_ENV+=		MKCATPAGES=no
MAKE_ENV+=		MKFILESDIR=${PREFIX}/share/mk
MAKE_ENV+=		NOSYSMK=1

AUTO_MKDIRS=		yes

PKGDOCDIR=		share/doc/mk-configure
EGDIR=			share/examples/mk-configure

post-install:
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/"${i}" ${DESTDIR}${PREFIX}/${PKGDOCDIR}
.endfor
	cp -Rp ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS && exists(/usr/xpg4/bin/awk)
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/usr/bin/awk
REPLACE.awk.new=	/usr/xpg4/bin/awk
REPLACE_FILES.awk=	mkc_check_version
.endif

.include "../../mk/bsd.pkg.mk"

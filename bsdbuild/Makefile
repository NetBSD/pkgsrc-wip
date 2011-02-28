# $NetBSD: Makefile,v 1.2 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=	bsdbuild-102608
CATEGORIES=	devel
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/bjs/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hypertriton.com/bsdbuild/
COMMENT=	BSD-licensed portable build system

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	*.pl
REPLACE_SH=	mkdep configure
###
### XXX until we have proper glue, take care to set these when
###	using this in a package.
###
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-libtool=${LIBTOOL:Q}
###
### XXXX Manual page installation really needs fixing!
###
CONFIGURE_ARGS+=	--with-manpages=no

AUTO_MKDIRS=		yes

###
### XXX fixup manual page installation
###
post-install:
	for n in 1 5; do \
	    for fn in ${WRKSRC}/${PKGMANDIR}/*.$${n}; do \
		${INSTALL_MAN} $${fn}	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man$${n}/ ; \
		done;			\
	done


.include "../../mk/bsd.pkg.mk"

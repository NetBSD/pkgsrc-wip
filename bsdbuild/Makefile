# $NetBSD: Makefile,v 1.7 2013/01/27 15:21:08 othyro Exp $
#

DISTNAME=	bsdbuild-3.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://stable.hypertriton.com/bsdbuild/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hypertriton.com/bsdbuild/
COMMENT=	BSD-licensed portable build system
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=		*.pl
REPLACE_SH=		mkdep configure
###
### XXX until we have proper glue, take care to set these when
###	using this in a package.
###
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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

# $NetBSD: Makefile,v 1.1.1.1 2008/07/08 15:51:15 bsadewitz Exp $
#

DISTNAME=	zsh-4.3.6
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zsh/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://zsh.sourceforge.net/
COMMENT=	Z Shell

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

WITH_TERM_LIBS=		# empty

.include "options.mk"

.if empty(WITH_TERM_LIBS)
.  include "../../mk/termcap.buildlink3.mk"
WITH_TERM_LIBS+=	${TERMCAP_TYPE:Nnone}
.endif

CONFIGURE_ARGS+=	--with-term-libs=${WITH_TERM_LIBS:M*:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

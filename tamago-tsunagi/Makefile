# $NetBSD: Makefile,v 1.3 2015/04/04 15:15:44 makoto Exp $

DISTNAME=	tamago-tsunagi-5.0.7.1
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=tamago-tsunagi/62701/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/tamago-tsunagi/
COMMENT=	IM(egg) for (Free)Wnn, Canna, sj3 and Anthy even after Emacs-24.3
LICENSE=	gnu-gpl-v2

CONFLICTS=	tamago-anthy-[0-9]*
CONFLICTS+=	tamago-[0-9]*

GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.9 2015/10/10 01:57:53 ryoon Exp $

DISTNAME=	rakudo-star-2015.11
CATEGORIES=	lang perl6
MASTER_SITES=	http://rakudo.org/downloads/star/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rakudo.org/
COMMENT=	Perl 6 reference implementation
LICENSE=	artistic-2.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake
PLIST_SRC+=		${PLIST_SRC_DFLT}
.if (${OPSYS} != "Darwin")
PLIST_SRC+=		PLIST.shared
.endif

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX} --backends=moar

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../wip/nqp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

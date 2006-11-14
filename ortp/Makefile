# $NetBSD: Makefile,v 1.3 2006/11/14 19:20:33 shattered Exp $
#

DISTNAME=		ortp-0.7.1
CATEGORIES=		net
MASTER_SITES=		http://download.savannah.nongnu.org/releases/linphone/ortp/sources/

MAINTAINER=		zul@netbsd-fr.org
HOMEPAGE=		http://www.linphone.org/index.php/v2/code_review/ortp
COMMENT=		Real-time Transport Protocol stack

GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

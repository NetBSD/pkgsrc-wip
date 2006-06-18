# $NetBSD: Makefile,v 1.1.1.1 2006/06/18 16:30:50 thomasklausner Exp $
#

DISTNAME=		rdup-0.2.13
CATEGORIES=		sysutils
MASTER_SITES=		http://miek.nl/projects/rdup/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://miek.nl/projects/rdup/
COMMENT=		Backup utility listing changed files only

DEPENDS+=		bash>=3.0:../../shells/bash

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

REPLACE_INTERPRETER+=   bash
REPLACE.bash.old=       .*/bin/bash
REPLACE.bash.new=       ${LOCALBASE}/bin/bash
REPLACE_FILES.bash=     sh-tools/crypt.sh.in sh-tools/dump-here.sh.in \
	sh-tools/dump.sh.in sh-tools/gzip.sh.in sh-tools/hist.sh.in \
	sh-tools/mirror.sh.in sh-tools/yesterday.sh.in sh-restore/rorrim.sh.in \
	sh-restore/monthday.sh.in sh-restore/restore.sh.in

post-install:
	${RMDIR} ${PREFIX}/etc/rdup

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD$

DISTNAME=	translate-toolkit-2.3.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=translate/}
GITHUB_PROJECT=	translate
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://toolkit.translatehouse.org/
COMMENT=	Essential Toolkit for Localization Engineers
LICENSE=	gnu-gpl-v1

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=1.9.0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch>=0:../../textproc/py-diff-match-patch/

USE_LANGUAGES=	c

REPLACE_BASH=	tools/*
USE_TOOLS+=	bash:run

PYTHON_VERSIONS_ACCEPTED=	36 35 34 27

post-extract:
	${RM} ${WRKSRC}/tools/mozilla/build_firefox.sh
	${RM} ${WRKSRC}/tools/mozilla/buildxpi.py
	${RM} ${WRKSRC}/tools/mozilla/get_moz_enUS.py
	${RMDIR} ${WRKSRC}/tools/mozilla/

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

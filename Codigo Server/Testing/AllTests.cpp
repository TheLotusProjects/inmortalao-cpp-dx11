#include <stdio.h>

#include "gtest/gtest.h"


#include "../src/Conexion/Messagin/ConnectUser.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



TEST(ConnectUserTest, Mensajes) {

    ConnectUser* connectUser = new ConnectUser();
    
    Resources* recursos = new Resources();
    connectUser->setRecursos(recursos);
    
    Cuenta* cuenta = new Cuenta("{ \"_id\" : \"marius\", \"password\" : \"1\", \"personajes\" : [ { \"nombre\" : \"Marius\", \"head\" : 102, \"body\" : 53, \"casco\" : 2, \"weapon\" : 2, \"shield\" : 2, \"nivel\" : 50, \"map\" : 49, \"x\" : 50, \"y\" : 50, \"clase\" : 2, \"tipPet\" : 9, \"items\" : [ { \"slot\" : 1, \"objindex\" : 1601, \"amount\" : 1 } ], \"hechizos\" : [ { \"slot\" : 1, \"hindex\" : 2 } ], \"privilegies\" : 1, \"account\" : 1, \"bandera\" : 0, \"heading\" : 3, \"mapHp\" : 353, \"minHp\" : 353, \"maxMan\" : 1807, \"minMan\" : 1807, \"maxSta\" : 790, \"minSta\" : 0, \"gld\" : 123, \"elu\" : 0, \"exp\" : 0, \"minAgua\" : 100, \"minHam\" : 100, \"fuerza\" : 6, \"agilidad\" : 20 } ] }");
    
    (*recursos->cuentas)["1"] = cuenta;
    
    string asd = connectUser->action("","1");
    
    std::cout<< asd;
    
    EXPECT_EQ(1, 1);

}

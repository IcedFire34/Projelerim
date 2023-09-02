class Product{
  late int id;
  late String name;
  late String description;
  late double unitPrice;

  Product(String name,String description,double unitPrice){
    this.name= name;
    this.description=description;
    this.unitPrice=unitPrice;
  }
  Product.withId(int id,String name,String description,double unitPrice){
    this.id=id;
    this.name= name;
    this.description=description;
    this.unitPrice=unitPrice;
  }


}